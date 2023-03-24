#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
//O(nlogn) - average case running
//O(nkare) - worst case running

void bas(int A[], int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");
}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b; 
	*b = temp;
}
int partition(int liste[], int start, int end);
void quickSort(int liste[], int start, int end);
void shuffle(int number[25], int n) {
	int i, temp, r;
	for (i = 0;i < n - 1;i++) {
		r = rand() % (n - 1 - i);
		//printf("%d\n", r);
		temp = number[i];
		number[i] = number[r];
		number[r] = temp;
	}
}


int main() {
	srand(time(NULL));
	int A[N];
	for (int i = 0; i < N; i++) {
		A[i] = 1 + rand() % 25;
	}
	bas(A, N);
	shuffle(A, N);
	quickSort(A, 0, N - 1);
	bas(A, N);

}
/*int partition(int liste[], int start, int end) {
	int pivot = liste[start];
	int partitionIndex = start + 1;
	for (int i = partitionIndex; i <= end; i++) {
		if (liste[i] <= pivot) {
			swap(&liste[i], &liste[partitionIndex]);
			partitionIndex++;
		}
	}
	swap(&liste[partitionIndex], &liste[start]);
	return partitionIndex;

}*/

int partition(int liste[], int start, int end) {

	int i = start, j = end;
	int pivot = liste[start];
	while (i < j) {
		while (liste[i] <= pivot && i<end) {
			i++;
		}
		while (liste[j] >= pivot && j > start) {
			j--;
		}
		if(i<j) //bu kýsým olmasa iki while'dan son j i'yi geçmesine ve pivot elemanýn koyulmasý gereken yer bulunmasýna 
				//raðmen swap edecekler ve bu bizim istediðimiz bir þey deðil.
			swap(&liste[i], &liste[j]);
	}//j i'yi geçtiði anda pivot j'de doðru yerde demektir.
	swap(&liste[start], &liste[j]);
	return j;
}

void quickSort(int liste[], int start, int end) {
	if (start < end) {
		int pivotIndex = partition(liste, start, end);
		quickSort(liste, start, pivotIndex - 1);
		quickSort(liste, pivotIndex + 1, end);
	}
}

