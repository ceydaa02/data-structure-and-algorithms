#include<stdio.h>
/*
insertion sort: 0'dan i ye kadar s�ras�yla ilk 1, 2, 3 tane terimi
s�ral�yor sonra bu terim say�s�n� artt�ra artt�ra en son elimizde 
s�ral� bir dizi oluyor.
O(Nkare) de �al���r
*/

void swap(int* x, int* y);
void compareToLeft(int A[], int i, int N);
void bas(int A[], int N) {
	for (int i = 0; i < N; i++) {
		printf("\t %d", A[i]);
	}
	printf("\n");
}
int main() {
	int A[5] = { 3,7,2,5,1 };
	bas(A, 5);

	//insertion sort k�sm�
	for (int i = 0; i < 5; i++) {
		compareToLeft(A, i, 5);
		bas(A, 5);
	}

}

void swap(int* x, int* y) {
	int temp = *y;
	*y = *x;
	*x = temp;
}
void compareToLeft(int A[], int i, int N) {
	for (int j = i; j > 0; j--) {
		if (A[j] < A[j - 1])
			swap(&A[j], &A[j - 1]);
		else break;
	}
}