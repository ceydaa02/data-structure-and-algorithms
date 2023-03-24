
#include<stdio.h>

int binary_search(int liste[], int bas, int son, int istenensayi);
int main() {
	int vals[] = { -78, -75,-15,-8,-3,-1,5,9, 15, 15, 78, 94, 193 };
	int boyut = sizeof(vals) / sizeof(vals[0]);

	for (int i = 0; i < boyut; i++) {
		int sayi = binary_search(vals, i+1, boyut, -vals[i]);
		if (sayi != -1)
			printf("Eslesme saglandi !!! %d -- %d\n", vals[i], vals[sayi]);
	}
	return 0;
}

int binary_search(int liste[], int bas, int son, int istenensayi) {
	while (bas < son) {
		int orta = bas + (son - bas) / 2;
		if (liste[orta] == istenensayi)
			return orta;
		if (liste[orta] < istenensayi)
		{
			bas = orta + 1;
		}
		else
			son = orta - 1;


	}
	return -1; 
}