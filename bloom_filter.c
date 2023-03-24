#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

#define N 500
#define NR 50
#define R 50

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int array[], int n)
{
	int i, j, min_element;
	for (i = 0; i < n - 1; i++)
	{
		min_element = i;
		for (j = i + 1; j < n; j++)
			if (array[j] < array[min_element])
				min_element = j;
		swap(&array[min_element], &array[i]);
	}
}

int dropDuplicates(int array[], int n) {
	int prev = 0, curr = 1, del = 0;
	while (curr < n) {
		if (array[curr] != array[curr - 1]) {
			curr++;
		}
		else {
			array[curr - 1] = INT_MAX;
			del++;
			curr++;
		}
	}
	return del;
}

unsigned int djb2(const void* _str) {
	const char* str = _str;
	unsigned int hash = 5381;
	char c;
	while ((c = *str++)) {
		hash = ((hash << 5) + hash) + c;
	}
	return hash%1200;
}

unsigned int jenkins(const void* _str) {
	const char* key = _str;
	unsigned int hash, i;
	while (*key) {
		hash += *key;
		hash += (hash << 10);
		hash ^= (hash >> 6);
		key++;
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash%1200;
}

int main() {

	int isRead[N];
	int willRead[R];

	/*
	Create a list of bits that some arbitrary indexes set to 1
	and others to 0. Which means if the article is read, the index set to 1, 
	otherwise the index set to 0.
	*/
	srand(time(0));
	for (int i = 0; i < R; i++) {
		willRead[i] = rand() % N;
	}
	selectionSort(willRead, R);

	int del = dropDuplicates(willRead, R);
	selectionSort(willRead, R);

	int p = 0;
	for (int i = 0; i < N ; i++) {
		if (willRead[p] == i) {
			if (p < R - del) {
				isRead[i] = 1;
				p++;
			}
		}
		else isRead[i] = 0;
	}


	/*
	Read medium_post.txt file and implement
	bloom filter algoritm to posts that have been seen.
	*/
	int bloomFilter[1200];

	FILE* fp = fopen("medium_posts.txt", "r");
	if (fp == NULL) {
		printf("Couldn't find the file %s.\n", "medium_posts.txt");
		exit(1);
	}

	int i = 0;
	int number;
	char postNames[100];
	while (1) {
		if (fscanf(fp, "%d. %[^,\n]", &number, postNames) == EOF) {
			break;
		}
		//printf("\n%s\n", postNames);
		if (isRead[i]) {
			unsigned int djb2_value = djb2(postNames);
			bloomFilter[djb2_value] = 1;
			unsigned int jenkins_value = jenkins(postNames);
			bloomFilter[jenkins_value] = 1;
		}
		i++;
		if (i == N) {
			fseek(fp, 0, SEEK_SET);
			break;
		}
	}

	/*
	Generate a list that will probably be recommended
	*/
	int random[NR];
	int r = 0;
	for (int k = 0; k < NR; k++) {
		r = rand() % (N + 1);
		if (!isRead[r])
			random[k] = r;
		else k--;
	}
	selectionSort(random, NR);
	int dup = dropDuplicates(random, NR);
	selectionSort(random, NR);

	i = 0;
	int j = 0;
	int a = 0;
	printf("\n\tWe've recommend you to read these top-read articles:\n");

	/*
	Recommend(print) the names of five arbitrary articles that have definetly not seen. 
	*/
	while (1) {
		if (fscanf(fp, "%d. %[^,\n]", &number, postNames) == EOF) {
			break;
		}
		//printf("\n%s\n", postNames);
		unsigned int djb2_value = djb2(postNames);
		unsigned int jenkins_value = jenkins(postNames);
		if (random[j] == i && j < NR-dup && a < 5) {
			if (bloomFilter[djb2_value] == 0 || bloomFilter[jenkins_value] == 0) {
				a++;
				printf("\t\t%s\n", postNames);
			}
			j++;
		}
		if (j == NR) break;
		if (a == 5) break;
		i++;
	}

	/* close file */
	fclose(fp);

	return 0;
}