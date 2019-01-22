#include<stdio.h>
#include<stdlib.h>
struct List
{
	int key=1,num=NULL;
	void AddList(int a);
	void MinusList();
	void PrintList();
	List* NextList = (List*)malloc(sizeof(List)*10);
};


int main() {
	List a;
	a.AddList(1);
	a.AddList(2);
	a.PrintList();
	a.MinusList();
	a.PrintList();
}

void List::AddList(int a)
{
	if (num != NULL) {
		for (int i = 1; i <= key; i++) {
			NextList[i].num = num;
			num = a;
		}
	}
	else if (num == NULL) {
		num = a;
	}
	key++;
}

void List::MinusList()
{
	for (int i = 1; i <=key; i++) {
		num = NULL;
		NextList->num = NULL;
	}
	key = 1;
}

void List::PrintList()
{
	if (num != NULL) {
		for (int i = 1; i < key;i++) {
			printf("%d ", NextList[i].num);
		}
	}
	else if (num == NULL) {
		printf("데이터가 없습니다.");
	}
	
}
