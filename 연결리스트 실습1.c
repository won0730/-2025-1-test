#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

//ù ��� ���� �Լ� ���� ��� �տ� ����ؼ� �߰���
ListNode *insert_first(ListNode *head, element value) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode)); //�����Ҵ�
    p->data = value;  //�����ͺκп� �� ����
    p->link = head;  // ������� ��ũ�� ���� ��� ����
    head = p;  //��带 �� ���� �ٲ�

    return head;
}
//���Ḯ��Ʈ ���
void print_list(ListNode *head) {
    //��ũ�� �� ���ö����� �������� �̵��ϸ鼭 ���
    for (ListNode *p = head; p != NULL; p = p->link) { 
        printf("%d->", p->data);
    }
    printf("NULL \n");
}

//�ּڰ� �ִ� ��� �Լ�
int MinMaxfromList(ListNode *head) {
    int min = head->data;  
    int max = head->data;  //�ʱ� ���� ��� ������ ����
    for (ListNode *p = head; p != NULL; p = p->link) {
        if (p->data > max)  //��带 �̵��ϸ鼭 �ʱ� ���� ���Ͽ� ����
            max = p->data;
        if (p->data < min)
            min = p->data;
    }
    printf("�ִ� = %d\n�ּڰ� = %d\n", max, min);
    return 0;
}


int main(void) {
    ListNode* head = NULL;
    head = insert_first(head, 10);
    head = insert_first(head, 13);
    head = insert_first(head, 8);
    head = insert_first(head, 33);
    head = insert_first(head, 21);
    print_list(head);

    MinMaxfromList(head);
    return 0;
}
