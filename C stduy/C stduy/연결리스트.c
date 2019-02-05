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
		printf("삭제할 데이터가 없습니다.\n");
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
		printf("삭제할 데이터가 없습니다.\n");
	}
}

void SearchKeyListDelete(list* List, int key) {
	if (key == 1 && List->headNode->NextLink == NULL) {
		printf("%d 번째 리스트의 데이터를 삭제해보겠습니다.\n", key);
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
	else if (TestList == NULL) {
		printf("데이터가 없습니다.\n");
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
		printf("1번 첫 번째 리스트에 입력 2번 마지막 리스트에 입력 3번 원하는 위치를 찾아 뒤에 입력 4번 첫 번째 리스트 삭제 5번 마지막 리스트 삭제 6번 원하는 위체를 찾아 삭제 c를 입력시 종료");
		scanf_s("%c", &pick);
		switch (pick)
		{
		case '1':
			printf("데이터 값을 입력하세요 : ");
			scanf_s("%d", &data);
			FirstListAdd(TestList, data);
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
		case '4':
			printf("첫 번째 리스트를 삭제해보겠습니다.\n");
			FirstListDelete(TestList);
			PrintList(TestList);
			break;
		case '5':
			printf("마지막 리스트를 삭제해보겠습니다.\n");
			LastListDelete(TestList);
			PrintList(TestList);
			break;
		case '6':
			printf("키 값 : ");
			scanf_s("%d", &key);
			SearchKeyListDelete(TestList, key);
			PrintList(TestList);
			break;
		}
		getchar();

	}
}