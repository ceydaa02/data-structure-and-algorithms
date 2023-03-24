#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
/*heap sort with binary trees
* //O(nlogn)
*   if i -> parent, 
	2i+1 -> left child, 
	2i+2 -> right child
	
	else if i -> child
	(i-1)/2 -> parent
*/
//min heap
//sað taraftaki min deðer veya sol taraftaki max deðer
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int liste[], int i, int n);
void heapsort(int liste[], int n);
void bas(int A[], int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");
}



int main() {
	int A[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		A[i] = 1 + rand() % 25;

	}
	bas(A, N);
	heapsort(A, N);
	printf("Sorted array is \n");
	bas(A, N);
	
	return 0;
}

void heapify(int liste[], int i, int boyut) {
	int lowest = i; 
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left<boyut && liste[left]<liste[lowest]) 
		lowest = left;

	if (right<boyut && liste[right]<liste[lowest])
		lowest = right;

	if (lowest != i) {
		swap(&liste[lowest], &liste[i]);
		heapify(liste, lowest, boyut);
	}
}
void heapsort(int liste[], int n) {
	//  n/2-1 : listedeki en son elemanýn ebeveyni
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(liste, i, n);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(&liste[0], &liste[i]);
		heapify(liste, 0, i);
	}
}

//max heap
/*#include <stdio.h>

// Function to swap the the position of two elements
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int n, int i) {
	// Find largest among root, left child and right child
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	// Swap and continue heapifying if root is not largest
	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

// Main function to do heap sort
void heapSort(int arr[], int n) {
	// Build max heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Heap sort
	for (int i = n - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);

		// Heapify root element to get highest element at root again
		heapify(arr, i, 0);
	}
}

// Print an array
void printArray(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver code
int main() {
	int arr[] = { 1, 12, 9, 5, 6, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	printf("Sorted array is \n");
	printArray(arr, n);
}*/