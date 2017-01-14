#include <stdio.h>

typedef struct {
	int a;
	int b;
	char c;
} MyStruct;

printMyStruct(MyStruct);
sumMyStruct(MyStruct*, MyStruct);

int main () {
	MyStruct ms = {12,23,'1'};
	MyStruct ms2 = {11,12,'1'};
	printMyStruct(ms);
	sumMyStruct(&ms, ms2);
	printMyStruct(ms);
	return 0;
}

printMyStruct(MyStruct ms) {
	printf("MyStruct: %d %d %c \n", ms.a, ms.b, ms.c);
}

sumMyStruct(MyStruct* ms, MyStruct ms2) {
	ms->a += ms2.a;
	ms->b += ms2.b;
	ms->c += ms2.c;
}
