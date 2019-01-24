#include<stdio.h>
#include<malloc.h>
typedef struct Node {
	char data[4];
	node* NextLink;

}node;

typedef struct List {
	node* headNode;
}list;

list* CreateNullList() {
	list* nullList;
	nullList = (list*)malloc(sizeof(list));
	nullList->headNode = NULL;
	return nullList;
}

int main() {
	
}