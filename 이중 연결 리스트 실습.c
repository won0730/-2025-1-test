#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
}DlistNode;

// 이중 연결 리스트를 초기화
void init(DlistNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

//삽입연산
void dinsert(DlistNode* before, element data) {
	DlistNode* newnode = (DlistNode*)malloc(sizeof(DlistNode));
	newnode->data = data;

	newnode->llink = before;
	newnode->rlink = before->rlink;

	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void print_dlist(DlistNode* phead)
{
	DlistNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

DlistNode* search(DlistNode* head, element data) {
	DlistNode* p;
	for (p = head->rlink; p != head; p = p->rlink) {  //헤드노드부터 루프를 돔 오른쪽으로
		if (p->data == data)  //만약 찾는 데이터 값이면

			/* 특정값 삭제 함수
			p->llink->rlink = p->rlink;
			p->rlink->llink = p->llink;
			free(p);*/

			return p;
	}
	return NULL;
}

int main(void)
{
	int count;
	DlistNode* head = (DlistNode*)malloc(sizeof(DlistNode));
	init(head);
	dinsert(head, 1); 
	dinsert(head, 2);
	dinsert(head, 3);
	dinsert(head, 4);
	print_dlist(head);

	element data;
	printf("탐색할 값: ");
	scanf_s("%d", &data);

	if (search(head, data) != NULL)
		printf("값이 리스트 안에 있습니다. \n ");
	else
		printf("값이 리스트 안에 없습니다. \n ");

	return 0;
}