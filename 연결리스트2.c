#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* next;
} ListNode;

//����� ���� �����Ҵ�
ListNode* create_node(element data) {
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) {
		fprintf(stderr, "�޸� �Ҵ� ����\n");
		exit(1);
	}
	new_node->data = data;  //�� ��忡 ������
	new_node->next = NULL;  //�� ����� ��ũ�� �η� ����
	return new_node;  //��ȯ
}

ListNode* insert_first(ListNode* head, element data) {
	//���� �� ��� ���� �Լ� ������� ������ �����Ҵ� �� �ʿ� ����
	ListNode* new_node = create_node(data); 
	new_node->next = head; 
	head = new_node;
	return head;
}

void print_list(ListNode* head) {
	ListNode* current = head;
	printf("(");
	while (current != NULL) {
		printf("%d", current->data);
		if (current->next != NULL) {
			printf(", ");
		}
		current = current->next;
	}
	printf(") \n");
}

//����Ʈ���� ã�� �Լ�
ListNode* search_list(ListNode* head, element x) {
	ListNode* current = head; //���簪�� �ʱⰪ�� ���� ����(������ �̵��ϸ鼭 ã��)
	while (current != NULL) {  //���� ���� ���� �ƴҶ�
		if (current->data == x) {  //���� ���� ã����
			return current;  //���� ��� ��ȯ
		}
		current = current->next;  //���� ���� �̵�
	}
	return NULL;  //�ƿ� ��ã���� �� ��ȯ
}

int main(void) {
	ListNode* head = NULL;

	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);
	if (search_list(head, 30) != NULL)  //30�� ã�µ� ��ȯ���� �ΰ��� �ƴϸ� ã��
		printf("����Ʈ���� 30�� ã�ҽ��ϴ�. \n");
	else
		printf("����Ʈ���� 30�� ã�� ���߽��ϴ�. \n");
	return 0;
}