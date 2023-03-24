#include<stdio.h>
int binarySearchRecursive(int dizi[], int bas, int son, int aranan);
int binarySearchIterative(int dizi[], int bas, int son, int aranan);
int main() {
	int dizi1[] = { -225, -123, -13, -5, 5, 15, 33, 48, 123, 225 };
	int N = sizeof(dizi1) / sizeof(dizi1[0]);
	for (int i = 0; i < N; i++) {
		int degerR = binarySearchRecursive(dizi1, 0, N-1, -dizi1[i]);
		if (degerR != -1) {
			printf("\t\n Eslesme saglandi!! Recursive:  %d   %d", dizi1[i], dizi1[degerR]);
		}
	
	}
	printf("\n\n");
	for (int i = 0; i < N; i++) {
		int degerI = binarySearchIterative(dizi1, i+1, N , -dizi1[i]);
		if (degerI != -1) {
			printf("\t\n Eslesme saglandi!! Iterative:  %d   %d", dizi1[i], dizi1[degerI]);
		}
	}
	return 0;
}
int binarySearchRecursive(int dizi[], int bas, int son, int aranan) {
	if (bas <= son) {
		int orta = bas + (son - bas) / 2;
		if (aranan == dizi[orta]) {
			return orta;
		}
		if (aranan > dizi[orta]) {
			return binarySearchRecursive(dizi, orta + 1, son, aranan);
		}
		if (aranan > dizi[orta]) {
			return binarySearchRecursive(dizi, bas, orta - 1, aranan);
		}

	}
		return -1;
}

int binarySearchIterative(int dizi[], int bas, int son, int aranan) {
	while (bas <= son) {
		int orta = bas + (son - bas) / 2;

		if (dizi[orta] == aranan)
			return orta;

		if (dizi[orta] < aranan) {
			bas = orta + 1;

		}
		else son = orta - 1;
	}
	return -1;
}
