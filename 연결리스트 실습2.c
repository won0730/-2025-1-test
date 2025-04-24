#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

ListNode *insert_first(ListNode *head, element value) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));  //�����Ҵ�
    p->data = value; //�� ����
    p->link = head;  //��带 �� ����� ��ũ�� ����
    head = p;  //�� ��带 ����
    return head;  //�� ��� ��ȯ
}

void print_list(ListNode *head) {
    for (ListNode *p = head; p != NULL; p = p->link) {
        printf("%d->", p->data);
    }
    printf("NULL \n");
}

//���� �Լ�
ListNode *delete_node(ListNode* head, element value) {
    ListNode *removed = head; //���� Ž������ ��� ���� ����
    ListNode *pre = NULL;  //�������

    if (head == NULL)
        return NULL;  //��尡 ���̸� �� ����Ʈ

    //���� �����Ϸ��� ���� ����
    else if (head->data == value) { 
        removed = head; //��带 ���� ���� ����
        head = head->link;  //��� ���� ��带 ���� ����
        free(removed);  //���� ��� �޸� ����
        return head;  //�ٲ� ��� ��ȯ
    }
    
    // ���� Ž������ ���� �ƴҶ� �ݺ�
    while (removed != NULL) {
        if (removed->data == value) {  //���� ���� ���� ���� ���̸�
            pre->link = removed->link;  //���ﰪ�� ��ũ�� �� ����� ��ũ�� ����
            free(removed);  //���� ��� �޸� ��ü
            return head;  //��� ��ȯ
        }

        //��ã���� ��� ��带 �̵���
        pre = removed;  //���� ���� ���� ������ ����
        removed = removed->link;  //���� ��ũ�� ����� �����ؼ� ���� ���� �Ѿ
    }
    return head;
}

int main(void) {
    ListNode *head = NULL;
    element value;
    head = insert_first(head, 10);
    head = insert_first(head, 13);
    head = insert_first(head, 8);
    head = insert_first(head, 33);
    head = insert_first(head, 21);
    print_list(head);

    printf("������ ���� �Է��Ͻÿ�: ");
    scanf_s("%d", &value);

    //�����Լ� ����
    head = delete_node(head, value);
    print_list(head);  //�ٽ� ���

    return 0;
}