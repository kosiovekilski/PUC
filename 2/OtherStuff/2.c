#include <stdio.h>
#define SIZE 20

int i;

void initArray (int *);
void printArray (int []);
int  sumArray (int []);
void revArray (int *);
void binArray (int *);
void binPrintArray (int []);

int main() {
	int array [SIZE];
	initArray (array);
	binPrintArray (array);
	revArray (array);
	binArray (array);
	printArray (array);
	return 0;
}

void initArray (int *arr) {
	arr [0] = 0;
	for (i = 0; i + 1 < SIZE; i++) {
		arr [i+1] = arr [i] + 2;
	}
}

void printArray (int arr []) {
	for (i = 0; i < SIZE; i++) {
		printf("%d\t",arr [i]);
	}
}

int  sumArray (int arr []) {
	int sum = 0;
	for (i = 0; i < SIZE; i++) {
		sum += arr [i];
	}
	return sum;
}

void revArray (int *arr) {
	int tmp;
	for (i = 0; i < SIZE/2; i++) {
		tmp = arr [i];
		arr [i] = arr [SIZE - i - 1];
		arr [SIZE - i - 1] = tmp;
	}
}

void binArray (int *arr) {
	for (i = 0; i < SIZE; i++) {
		arr [i] = (arr [i]?1:0);
	}
}

void binPrintArray (int arr []) {
	printf ("bin: ");
	for (i = 0; i < SIZE; i++) {
		printf("%d", (arr [i]?1:0));
	}
	printf ("\n");
}
