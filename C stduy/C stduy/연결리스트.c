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


void ListKeySeting(list *List) {
	int *num = 1; 
		while (List->headNode->NextLink != NULL)
		{
			List->headNode->key = num;
			List->headNode = List->headNode->NextLink;
			num++;
		}
		if (List->headNode->NextLink == NULL) {
			List->headNode->key = num;
		}
}

list* CreateNullList() {
	list* nullList;
	nullList = (list*)malloc(sizeof(list));
	nullList->headNode = NULL;
	return nullList;
}

void FristListAdd(list *List, int data) {
	node *addNode;
	addNode = (node*)malloc(sizeof(node));
	addNode->data = data;
	addNode->NextLink = List->headNode;
	List->headNode = addNode;
	ListKeySeting(List);
}


void LastListAdd(list *List, int data) {
	node * addNode;
	addNode = (node*)malloc(sizeof(node));
	addNode->data = data;
	while (List->headNode->NextLink != NULL)
	{
		List->headNode = List->headNode->NextLink;
	}
	List->headNode->NextLink = addNode;
	ListKeySeting(List);
}

void SearchKeyListFrontAdd(list* List, int key, int data) {
	node* addNode;
	addNode = (node*)malloc(sizeof(node));
	addNode->data = data;
	while (List->headNode->NextLink != NULL)
	{
		if (List->headNode->key == key) {
			addNode->NextLink = List->headNode->NextLink;
			List->headNode->NextLink = addNode;
		}
	}
	ListKeySeting(List);
}

void SearchKeyListBackAdd(list* List, int key, int data) {
	node* addNode;
	addNode = (node*)malloc(sizeof(node));
	addNode->data = data;
	while (List->headNode->NextLink != NULL)
	{
		if (List->headNode->key == key) {
			FristListAdd(List, data);
			break;
		}
		else if (List->headNode->NextLink == key) {
			addNode->NextLink = List->headNode->NextLink;
			List->headNode->NextLink = addNode;
			break;
		}
	}
	ListKeySeting(List);
}

void PrintList(list*List) {
	if (List->headNode->NextLink == NULL) {
		printf("%d번째 리스트값은 %d입니다.", List->headNode->key, List->headNode->data);
	}
	else {
		while (List->headNode->NextLink != NULL)
		{
			if (List->headNode->data != NULL) {
				printf("%d번째 리스트 값은 NULL값입니다.", List->headNode->key);
			}
			else {
				printf("%d번째 리스트의 데이터값 : %d\n", List->headNode->key, List->headNode->data);
			}

		}
	}
}

list* CreateList() {
	list* List;
	List = (list*)malloc(sizeof(list));
	List->headNode = NULL;
}

int main() {
	list* a;
	a = CreateList();
	FristListAdd(a, 3);
	PrintList(a);
	LastListAdd(a, 50);
	PrintList(a);
}