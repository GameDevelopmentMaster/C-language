#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	node* beforeLink;
	node* NextLink;
	int data;
	int key;
}node;

typedef struct List {
	node* nodehead;
}list;


list* CreateList(list *List) {
	List = (list*)malloc(sizeof(list));
	List->nodehead = NULL;
	List->nodehead->NextLink = List->nodehead;
	return List;
}

void* FirstListAdd(list* List,int data) {
	node* Addnode;
	Addnode = (node*)malloc(sizeof(node));
	Addnode->data = data;
	Addnode->NextLink = List->nodehead->NextLink;
	List->nodehead = Addnode;
}

void* LastListAdd(list* List, int data) {
	node* Addnode;
	node* Chicknode = List->nodehead;
	Addnode	= (node*)malloc(sizeof(node));
	Addnode->data = data;
	if (Chicknode != NULL) {
		while (Chicknode->NextLink!=NULL)
		{
			Chicknode = Chicknode->NextLink;
		}
		Chicknode->NextLink = Addnode;
		Addnode->NextLink = List->nodehead;
	}
	else if (Chicknode == NULL) {
		List->nodehead = Addnode;
		Addnode->NextLink = List->nodehead;
	}
}

int main() {

}