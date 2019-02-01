#include<stdio.h>
#include<malloc.h>
typedef struct TEST {
	int a;
	char NextLink;
}test;

void Test(test* test) {
}

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

void IntChage(int *a) {
	printf("%d\n", *a);
	*a = 10;
	printf("%d\n", *a);
}

int main() {
	int *a, *b=1,c=0;
	IntChage(b);
	printf("%d", b);
	return 0;
}
