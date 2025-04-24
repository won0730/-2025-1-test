#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode* llink;  //��ũ �ΰ� �������� 
	struct DlistNode* rlink;
}DlistNode;

// ���� ���� ����Ʈ�� �ʱ�ȭ
void init(DlistNode* phead)
{
	phead->llink = phead;  
	phead->rlink = phead;  //����� �ϳ��� ���� ������ ��ũ�� �ڱ� �ڽ��� ����Ű���� ��
}

//���Կ���
void dinsert(DlistNode* before, element data) {
	DlistNode* newnode = (DlistNode*)malloc(sizeof(DlistNode));  //���ο� ��� �����Ҵ�
	newnode->data = data;  //�� ��忡 ������ ����

	newnode->llink = before; //�� ����� ���� ��ũ�� �� ���� ����
	newnode->rlink = before->rlink;  //�� ����� ������ ��ũ�� �� ����� ������ ��ũ�� ����(����带 ����Ű�� ��ũ)

	before->rlink->llink = newnode; //�� ��尡 ���� ����Ű�� ���(������)�� ���� ��ũ�� �� ���� ����
	before->rlink = newnode;  //�� ����� ������ ��ũ�� ������ ����
}
//��������
void ddelete(DlistNode* head, DlistNode* removed) {
	if (removed == head) // ������ ��尡 ��������
		return;  //�������� ����

	//������ ����� ���� ��ũ�� ����Ű�� ����� ������ ��ũ�� ������� ������ ���� ����(�پ�Ѵ°�)
	removed->llink->rlink = removed->rlink;  
	//��������
	removed->rlink->llink = removed->llink;

	free(removed);  //�޸� ����
}

//��� �Լ�
void print_dlist(DlistNode* phead)
{
	DlistNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) { //������� ������ ��ũ���� �̵�(������ �ٽ� ���ƿö� ����)
		printf("<-| |%d| |-> ", p->data); //������ �� ���
	}
	printf("\n"); //�ٹٲ�
}

//�߰����� �Ѵܰ辿 ���
int main(void)
{
	DlistNode* head = (DlistNode*)malloc(sizeof(DlistNode));  //���̳���̱� ������ �����Լ������� �����Ҵ�
	init(head); //�ʱ�ȭ
	printf("�߰� �ܰ�\n");
	for (int i = 0; i < 5; i++) {
		// ��� ����� �����ʿ� ����(������� �����ʿ� �����ϴ°� �ƴ϶� ������� �������̱⶧���� ����ϸ� ������ �ݴ�)
		dinsert(head, i);
		print_dlist(head);
	}
	printf("\n���� �ܰ�\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);  //�޸� ����
	return 0;
}