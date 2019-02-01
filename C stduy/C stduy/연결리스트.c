#include<stdio.h>
#include<malloc.h>
typedef struct Node {
	int key;
	int data;
	struct node* NextLink;

}node;

typedef struct List {
	node* headNode;
}list;


void* ListKeySeting(list *List) {
	node *TestList = List->headNode;
	int num = 1;
	while (TestList->NextLink != NULL)
	{
		TestList->key = num;
		TestList = TestList->NextLink;
		num++;
	}
	if (TestList->NextLink == NULL) {
		TestList->key = num;
	}
}

void FristListAdd(list *List, int data) {
	node *addNode;
	addNode = (node*)malloc(sizeof(node));
	addNode->data = data;
	addNode->NextLink = List->headNode;
	List->headNode = addNode;
	List = ListKeySeting(List);
}


void LastListAdd(list *List, int data) {
	node * addNode;
	node * Link = List ->headNode;
	addNode = (node*)malloc(sizeof(node));
	addNode->NextLink = NULL;
	addNode->data = data;
	if (List->headNode == NULL)
	{
		List->headNode = addNode;
	}
	else {
		while (Link->NextLink != NULL)
		{
			Link = Link->NextLink;
		}
		Link->NextLink = addNode;
	}
	List = ListKeySeting(List);
}

void SearchKeyListFrontAdd(list* List, int key, int data) {
	node* addNode;
	node* Link = List->headNode;
	addNode = (node*)malloc(sizeof(node));
	addNode->data = data;
	while (Link!= NULL)
	{
		if (Link->key == key) {
			addNode->NextLink = Link->NextLink;
			Link->NextLink = addNode;
		}
		Link = Link->NextLink;
	}
	List = ListKeySeting(List);
}

void SearchKeyListBackAdd(list* List, int key, int data) {
	node* addNode;
	node* Link = List->headNode;
	addNode = (node*)malloc(sizeof(node));
	addNode->data = data;
	while (Link->NextLink != NULL)
	{
		if (Link->key == key) {
			FristListAdd(List, data);
			break;
		}
		Link = Link->NextLink;
	}
	List = ListKeySeting(List);
}

void PrintList(list*List) {
	node * TestList = List->headNode;
	while (TestList->NextLink != NULL)
	{
		if (TestList->data == NULL) {
			printf("%d번째 리스트 값은 NULL값입니다.\n", TestList->key);
		}
		else {
			printf("%d번째 리스트의 데이터값 : %d\n", TestList->key, TestList->data);
		}
		TestList = TestList->NextLink;
	}
	if (TestList != NULL && TestList->NextLink == NULL) {
		printf("%d번쨰 리스트의 데이터 값 : %d\n", TestList->key, TestList->data);
	}
	printf("\n");
}

list* CreateList() {
	list* List;
	List = (list*)malloc(sizeof(list));
	List->headNode = NULL;
}

int main() {
	char pick = 0;
	int data, key;
	list* TestList;
	TestList = CreateList();
	while (pick != 67 && pick != 99) {
		printf("1번 첫 번째 리스트에 입력 2번 마지막 리스트에 입력 3번 원하는 위치를 찾아 뒤에 입력 c를 입력시 종료");
		scanf_s("%c", &pick);
		switch (pick)
		{
		case '1':
			printf("데이터 값을 입력하세요 : ");
			scanf_s("%d", &data);
			FristListAdd(TestList, data);
			PrintList(TestList);
			break;
		case '2':
			printf("데이터 값을 입력하세요 : ");
			scanf_s("%d", &data);
			LastListAdd(TestList, data);
			PrintList(TestList);
			break;
		case '3':
			printf("데이터 값을 입력하세요 :");
			scanf_s("%d", &data);
			printf("키 값을 입력하세요 : ");
			scanf_s("%d", &key);
			SearchKeyListFrontAdd(TestList, key, data);
			PrintList(TestList);
			break;
		}
		getchar();

	}
}