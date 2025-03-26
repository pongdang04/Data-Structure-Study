/*#include<stdio.h>

typedef int LData;

typedef struct _node {
	LData data;
	struct _node* next;
}Node;

typedef struct _linkedList {
	Node* head;
	Node* cur;
	Node* before;
	int numOfData;
}LinkedList;

typedef LinkedList List;

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));//create DummyNode
	plist->head->next = NULL;//tail of DMY = NULL
	plist->numOfData = 0;
}

void FInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = plist->head->next; 
	plist->head = newNode;
	plist->numOfData++;
}

int LFirst(List* plist, LData* pdata) {
	if (plist->head->next == NULL) {
		return -1;
	}

	plist->before = plist->head;
	plist->cur = plist->before->next;
	*pdata = plist->cur->data;
	return 0;
}

int LNext(List* plist, LData* pdata) {
	if (plist->cur->next == NULL) {
		return -1;
	}
	
	plist->before = plist->before->next;//move foward
	plist->cur = plist->before->next;

	*pdata = plist->cur->data;
	return 0;
}

LData LRemove(List* plist) {
	LData data = plist->cur->data;

	plist->before->next = plist->cur->next;
	free(plist->cur);
	plist->cur = plist->before;

	return data;
}*/