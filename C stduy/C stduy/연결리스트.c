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
			printf("%d��° ����Ʈ ���� NULL���Դϴ�.\n", TestList->key);
		}
		else {
			printf("%d��° ����Ʈ�� �����Ͱ� : %d\n", TestList->key, TestList->data);
		}
		TestList = TestList->NextLink;
	}
	if (TestList != NULL && TestList->NextLink == NULL) {
		printf("%d���� ����Ʈ�� ������ �� : %d\n", TestList->key, TestList->data);
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
		printf("1�� ù ��° ����Ʈ�� �Է� 2�� ������ ����Ʈ�� �Է� 3�� ���ϴ� ��ġ�� ã�� �ڿ� �Է� c�� �Է½� ����");
		scanf_s("%c", &pick);
		switch (pick)
		{
		case '1':
			printf("������ ���� �Է��ϼ��� : ");
			scanf_s("%d", &data);
			FristListAdd(TestList, data);
			PrintList(TestList);
			break;
		case '2':
			printf("������ ���� �Է��ϼ��� : ");
			scanf_s("%d", &data);
			LastListAdd(TestList, data);
			PrintList(TestList);
			break;
		case '3':
			printf("������ ���� �Է��ϼ��� :");
			scanf_s("%d", &data);
			printf("Ű ���� �Է��ϼ��� : ");
			scanf_s("%d", &key);
			SearchKeyListFrontAdd(TestList, key, data);
			PrintList(TestList);
			break;
		}
		getchar();

	}
}