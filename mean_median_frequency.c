#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10


float mean(int dizi[], int eleman);
float median(int dizi[], int elemansayisi);
void selection(int val[], int eleman, int dizi[]);
void frequency(int A[], int buyukluk, int dizi[]);
float meanRecursive(int dizi[], int eleman);
int mod(int dizi[], int buyukluk);


int main() {
	int val[N];
	int sayilar[] = { 5, 36, 47, 145, 455, 564, 956, 956};
	int k = sizeof(sayilar) / sizeof(sayilar[0]);
	int yenidizi[N];
	int fredizi[6] = { 0,0,0,0,0,0 };
	
	printf("%d\n", k);
	srand(time(NULL));
	for (int i = 0; i < k; i++) {
		val[i] = 1 + rand() % 6;
		printf("%d ", val[i]);
	}
	printf("\n");
	selection(val, k, yenidizi);
	printf("\nOrtalama : %f\n", mean(val, k));
	printf("Recursive ortalama : %f\n", meanRecursive(val, k));
	printf("Medyan : %f\n", median(yenidizi, k));
	frequency(yenidizi, k, fredizi);

	printf("\nMOD : %d ", mod(fredizi, k));


	return 0;
}

void selection(int val[N], int eleman, int dizi[N]) {
	for (int k = 1; k < eleman; k++) {
		for (int i = 0; i + 1 < eleman; i++) {
			int tmp = 0;
			if (val[i] > val[i + 1]) {
				tmp = val[i + 1];
				val[i + 1] = val[i];
				val[i] = tmp;
			}
		}

	}
	for (int i = 0; i < eleman; i++) {
		dizi[i] = val[i];
		printf("%d ", val[i]);
	}
}
void frequency(int A[], int buyukluk, int dizi[]){

	for (int i = 0; i < buyukluk; i++) {
		(dizi[A[i] - 1]) ++;
	}

	
	for (int i = 0; i < 6; i++) {
		printf("frequency(%i) : % i\n", i + 1, dizi[i]);
	}

}
int mod(int dizi[], int buyukluk) {
	int max = 0;
	int k=0;
	for (int i = 0; i < buyukluk; i++) {
		if (dizi[i] > max) {
			max = dizi[i];
			k = i+1;
		}
	}
	return k;
}

float mean(int dizi[], int eleman) {
	float res = 0;
	for (int i = 0; i < eleman; i++) {
		res += dizi[i];
	}
	return res / eleman;
}

float meanRecursive(int dizi[], int eleman) {
	int res = 0;
	if (eleman == 1)
		return (float)dizi[0];
	
	else {
		return (meanRecursive(dizi, eleman - 1) * (eleman - 1) + dizi[eleman - 1]) / eleman;
	}
}

float median(int dizi[], int elemansayisi) {
	int orta;
	float sonuc;
	if (elemansayisi % 2 == 1) {
		orta = elemansayisi / 2 + 1;
		sonuc = dizi[orta-1];
	}
	else {
		orta = elemansayisi / 2;
		sonuc = (dizi[orta] + dizi[orta - 1]) / 2.0;
	}
	return sonuc;
}

