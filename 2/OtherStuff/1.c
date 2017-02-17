#include <stdio.h>
#define SIZE 10

void   inputArray (int*);
void   printArray (int[]);
double averageArray (int[]);
int    minIndex (int[]);

int main() {
	int array[SIZE];
	printf ("Array size = %d\n", SIZE);
	inputArray (array);
	printArray (array);
	printf ("Average array: %lf\n", averageArray(array));
	printf ("Min index: %d\n", minIndex(array));
	return 0;
}

void inputArray (int *arr) {
	printf ("INput array:\n");
	int i ;	
	for (i = 0; i < SIZE; i++) {
		printf ("A[%d]=",i);
		scanf ("%d", arr+i);
	}
}

void printArray (int arr[]) {
	int i;
	printf ("Print array:\n");
	for (i = 0; i < SIZE; i++) {
		printf ("A[%d]=%d\n",i, *(arr+i));
	}
}

double averageArray (int arr[]) {
	int i, sum = 0;
	for (i = 0; i < SIZE; i++) {
		sum += arr[i];
	}
	return (double) sum / SIZE;
}

int minIndex (int arr[]) {
	int i, index = 0;
	for (i = 0; i < SIZE; i++) {
		if (arr[i] < arr[index]) {
			index = i;
		}
	}
	return index;
}
