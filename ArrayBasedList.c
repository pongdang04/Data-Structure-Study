#include<stdio.h>
#define LIST_LEN 100
typedef int LData;

typedef struct ArrayList {
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
}List;

void ListInit(List* list) {
	list->numOfData = 0;
	list->curPosition = -1;
}

int LInsert(List* list, int data) {
	list->arr[list->numOfData] = data;
	list->numOfData++;
	return data;
}

int LFirst(List* list, int* data) {
	list->curPosition = 0;
	data = list->arr[list->curPosition];
}

int LNext(List* list, int* data) {
	list->curPosition++;
	data = list->arr[list->curPosition];
}

LRemove(List* list) {
	//move foward
	int i;
	for (i = list->curPosition; i < list->numOfData; i++) {
		list->arr[i] = list->arr[i + 1];
	}

	//delete
	list->numOfData--;
	list->curPosition--;
}

int LCount(List* list) {
	return list->numOfData;
}

int main() {
	List list;
	int data;

	LFirst(&list, &data);
	if (data == 22)
		LRemove(&list);
	else
		while (1) {
			LNext(&list, &data);
				if (data == 22) {
					LRemove(&list);
					break;
				}
		}
}