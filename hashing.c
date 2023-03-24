#include<stdio.h>
#include<stdlib.h>

#define N 20
typedef struct {
	int key;
	int value;
}data;
data list[27];
//key de value da bizim bildiðimiz deðiþkenler, key e göre hash leyip table'a yazýyoruz.

int hash(int x) {
	return x % 27;
}

void init_hash_table(data hash_table[]) {
	for (int i = 0; i < 27;i++) {
		hash_table[i].key = NULL;
	}
}

int put(data eleman) {
	int n = list[hash(eleman.key)].key; //verilen elemanýn 
		//key'in hashlenmiþ halinin listenin içindeki deðerinin key'i 
	if ( n == NULL) {
		list[hash(eleman.key)] = eleman;
	}
	else {
		int donus = 0;
		int indis = hash(eleman.key);
		while (list[indis].key != eleman.key && list[indis].key != NULL) {
			indis++;
			if (indis >= 27) {
				if (donus >= 1) {
					printf("hash table is full - %d - %d\n",eleman.key, eleman.value);
					return -1;
				}
				indis = indis % 27;
				donus++;
			}
		}
		list[indis] = eleman;

	}
	return 1;
}

int get(int k) {
	int n = list[hash(k)].key;
	if (n == k) {
		return list[hash(k)].value; 
	}
	else {
		int donus = 0;
		int indis = hash(k);
		while (list[indis].key != k && list[indis].key != NULL) {
			indis++;
			if (indis >= 27) {
				if (donus >= 1) {
					printf("kayit yok!\n");
					return -1;

				}
				indis = indis % 27;
				donus++;
			}
		}
		return list[indis].value;
	}
}


void bastir() {
	for (int i = 0;i < 27;i++) {
		printf("[key:%d value:%d]\n", list[i].key, list[i].value);
	}
	printf("\n");
}

int main() {
	init_hash_table(list);
	data data;


	data.key = 1;data.value = 66666;
	put(data);
	data.key = 255; data.value = 536854;
	put(data);
	data.key = 100;data.value = 77777;
	put(data);
	data.key = 300;data.value = 5867;
	put(data);
	data.key = 55;data.value = 853;
	put(data);
	data.key = 15;data.value = 3277;
	put(data);
	data.key = 28;data.value = 99999;
	put(data);
	data.key = 28;data.value = 42342;
	put(data);


	printf("%d \n", get(10));
	printf("%d \n", get(1));
	printf("%d \n", get(28));
	printf("%d \n", get(100));
	printf("%d \n", get(3424));
	printf("%d \n", get(2));
	bastir();

}