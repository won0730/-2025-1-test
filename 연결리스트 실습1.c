#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

//첫 노드 삽입 함수 기존 노드 앞에 계속해서 추가함
ListNode *insert_first(ListNode *head, element value) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode)); //동적할당
    p->data = value;  //데이터부분에 값 저장
    p->link = head;  // 새노드의 링크에 기존 헤드 저장
    head = p;  //헤드를 새 노드로 바꿈

    return head;
}
//연결리스트 출력
void print_list(ListNode *head) {
    //링크가 널 나올때까지 다음노드로 이동하면서 출력
    for (ListNode *p = head; p != NULL; p = p->link) { 
        printf("%d->", p->data);
    }
    printf("NULL \n");
}

//최솟값 최댓값 출력 함수
int MinMaxfromList(ListNode *head) {
    int min = head->data;  
    int max = head->data;  //초기 값을 헤드 값으로 저장
    for (ListNode *p = head; p != NULL; p = p->link) {
        if (p->data > max)  //노드를 이동하면서 초기 값과 비교하여 구함
            max = p->data;
        if (p->data < min)
            min = p->data;
    }
    printf("최댓값 = %d\n최솟값 = %d\n", max, min);
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
