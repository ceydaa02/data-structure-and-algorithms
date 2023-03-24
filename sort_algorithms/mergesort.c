#include <stdio.h>
void bas(int A[], int N) {
	for (int i = 0; i < N; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");
}


void merge(int A[], int C[], int low, int mid, int high) {
	// Copy
	for (int k = low; k <= high; k++)
		C[k] = A[k];
	//bas(C, 6);
	//printf("\n\t\t========\n");

	int i = low;
	int j = mid + 1;
	for (int k = low; k <= high; k++) {
		if (i > mid)
			A[k] = C[j++];
		else if (j > high)
			A[k] = C[i++];
		else if (C[j] < C[i])
			A[k] = C[j++];
		else
			A[k] = C[i++];
		bas(A, 6);
	}
}

void sort(int A[], int C[], int low, int high) {
	if (high <= low) return;
	int mid = low + (high - low) / 2;
	sort(A, C, low, mid);
	sort(A, C, mid + 1, high);
	merge(A, C, low, mid, high);
}


void mergesort(int A[], int N) {
	int C[7];
	sort(A, C, 0, N - 1);
}






//======================
int main() {

	//int A[6] = { 2, 3,7,1, 5, 6 };
	int C[7];

	//bas(A, 6);
	//printf("\n\t\t========\n");
	//mergesort(A, C, 0, 2, 5);
	//bas(A, 6);

	int A1[7]  = {9,8,7,6,5,4,3};

	mergesort(A1, 7);
	//int C1[7];
	//bas(A1, 7);
	//sort(A1, C1, 0, 6);
	//bas(A1, 7);

	//printf("\n\t\t========\n");
	//int A2[8]  = {5,8,7,6,5,5,5,5};
	//bas(A2, 8);
	//mergesort(A2, 8);
	//bas(A2, 8);


	return 0;
}



/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//O(NlogN)


void merge(int dizi[], int left[], int right[]);
void mergesort(int dizi[], int boyut);
void bas(int A[], int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");
}


int main(){
	int A[8] = { 45, 73, 6, 4, 56, 99, 21, 36 };
	int elemansayisi = sizeof(A) / sizeof(A[0]);
	mergesort(A, elemansayisi);
	bas(A, elemansayisi);

	return 0;
}



void merge(int dizi[], int left[], int leftn, int right[], int rightn) {


	int i = 0, j = 0, k = 0;
	while (i<leftn && j<rightn) {
		if (left[i] < right[j]) {
			dizi[k] = left[i];
			i++;
			//dizi[k++] = left[i++];
		}
		else {
			dizi[k] = right[j];
			j++;
			//dizi[k++] = right[j++];
		}
		k++;
	}
	while (i < leftn) {
		dizi[k] = left[i];
		i++;
		k++;
		//dizi[k++] = left[i++];
	}
	while (j < rightn) {
		dizi[k] = right[j];
		j++;
		k++;
		//dizi[k++] = left[j++];
	}
	
}

void mergesort(int dizi[], int boyut) {

	if (boyut < 2) return;
	int orta = boyut / 2;
	int* L = (int*)malloc(orta * sizeof(int));
	int* R = (int*)malloc((boyut-orta) * sizeof(int));

	for (int i = 0; i < orta; i++) {
		L[i] = dizi[i];
	}
	for (int i = orta; i < boyut; i++) {
		R[i - orta] = dizi[i];
	}
	mergesort(L, orta);
	mergesort(R, boyut-orta);
	merge(dizi, L, orta, R, boyut-orta);
	free(L);
	free(R);
}*/