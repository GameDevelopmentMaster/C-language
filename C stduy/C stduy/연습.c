#include<stdio.h>
#include<malloc.h>
typedef struct TEST {
	int a;
	char c;
}test;

test* CreateIntChange(){
	test* testStruct;
	testStruct = (test*)malloc(sizeof(test));
	testStruct = 3;
	return testStruct;
}

test* CreateCharChange() {
	test* testStruct;
	testStruct = (test*)malloc(sizeof(test));
	testStruct = NULL;
	return testStruct;
}

int main() {
	test* a;
	a = (test*)malloc(sizeof(test));
	a = CreateIntChange();
	printf("%d\n", a);
	a = CreateCharChange();
	printf("%d", a);
	getchar();
	return 0;
}