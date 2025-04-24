#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
}DlistNode;

// ���� ���� ����Ʈ�� �ʱ�ȭ
void init(DlistNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

//���Կ���
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
	for (p = head->rlink; p != head; p = p->rlink) {  //�������� ������ �� ����������
		if (p->data == data)  //���� ã�� ������ ���̸�

			/* Ư���� ���� �Լ�
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
	printf("Ž���� ��: ");
	scanf_s("%d", &data);

	if (search(head, data) != NULL)
		printf("���� ����Ʈ �ȿ� �ֽ��ϴ�. \n ");
	else
		printf("���� ����Ʈ �ȿ� �����ϴ�. \n ");

	return 0;
}