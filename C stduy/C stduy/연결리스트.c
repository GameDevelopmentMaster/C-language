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

void FirstListAdd(list *List, int data) {
	node *addNode;
	addNode = (node*)malloc(sizeof(node));
	addNode->data = data;
	addNode->NextLink = List->headNode;
	List->headNode = addNode;
	List = ListKeySeting(List);
}

void FirstListDelete(list* List) {
	if (List->headNode == NULL) {
		printf("������ �����Ͱ� �����ϴ�.\n");
	}
	else {
		node* CheckNode = List->headNode;
		List->headNode = List->headNode->NextLink;
		free(CheckNode);
		if (List->headNode != NULL) {
			List = ListKeySeting(List);
		}
	}
}

void LastListDelete(list*List) {
	if (List->headNode != NULL)
	{
		node* Checknode = List->headNode;
		while (Checknode->NextLink != NULL)
		{
			Checknode = Checknode->NextLink;
		}
		free(Checknode);
	}
	else if (List->headNode == NULL) {
		printf("������ �����Ͱ� �����ϴ�.\n");
	}
}

void SearchKeyListDelete(list* List, int key) {
	if (key == 1 && List->headNode->NextLink == NULL) {
		printf("%d ��° ����Ʈ�� �����͸� �����غ��ڽ��ϴ�.\n", key);
		List->headNode = NULL;
	}
	else {
		if (key == 1) {
			FirstListDelete(List);
		}
		else {
			node* Checknode= List->headNode;
			node* Checknode2 = Checknode;
			while (Checknode->NextLink != NULL||Checknode->key >=key)
			{
				if (Checknode->key == key) {
					Checknode2->NextLink = Checknode->NextLink;
					free(Checknode);
					break;
				}
				Checknode2 = Checknode;
				Checknode = Checknode->NextLink;
			}
		}
		List = ListKeySeting(List);
	}
}

void LastListAdd(list *List, int data) {
	node * addNode;
	node * Link = List->headNode;
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
	while (Link != NULL)
	{
		if (Link->key == key) {
			addNode = (node*)malloc(sizeof(node));
			addNode->data = data;
			addNode->NextLink = Link->NextLink;
			Link->NextLink = addNode;
		}
		Link = Link->NextLink;
	}
	List = ListKeySeting(List);
}

void PrintList(list*List) {
	node * TestList = List->headNode;
	if (TestList != NULL) {
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
	else if (TestList == NULL) {
		printf("�����Ͱ� �����ϴ�.\n");
	}
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
		printf("1�� ù ��° ����Ʈ�� �Է� 2�� ������ ����Ʈ�� �Է� 3�� ���ϴ� ��ġ�� ã�� �ڿ� �Է� 4�� ù ��° ����Ʈ ���� 5�� ������ ����Ʈ ���� 6�� ���ϴ� ��ü�� ã�� ���� c�� �Է½� ����");
		scanf_s("%c", &pick);
		switch (pick)
		{
		case '1':
			printf("������ ���� �Է��ϼ��� : ");
			scanf_s("%d", &data);
			FirstListAdd(TestList, data);
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
		case '4':
			printf("ù ��° ����Ʈ�� �����غ��ڽ��ϴ�.\n");
			FirstListDelete(TestList);
			PrintList(TestList);
			break;
		case '5':
			printf("������ ����Ʈ�� �����غ��ڽ��ϴ�.\n");
			LastListDelete(TestList);
			PrintList(TestList);
			break;
		case '6':
			printf("Ű �� : ");
			scanf_s("%d", &key);
			SearchKeyListDelete(TestList, key);
			PrintList(TestList);
			break;
		}
		getchar();

	}
}