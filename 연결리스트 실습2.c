#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

ListNode *insert_first(ListNode *head, element value) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));  //동적할당
    p->data = value; //값 저장
    p->link = head;  //헤드를 새 노드의 링크로 지정
    head = p;  //새 노드를 헤드로
    return head;  //새 헤드 반환
}

void print_list(ListNode *head) {
    for (ListNode *p = head; p != NULL; p = p->link) {
        printf("%d->", p->data);
    }
    printf("NULL \n");
}

//삭제 함수
ListNode *delete_node(ListNode* head, element value) {
    ListNode *removed = head; //현재 탐색중인 노드 헤드로 시작
    ListNode *pre = NULL;  //직전노드

    if (head == NULL)
        return NULL;  //헤드가 널이면 빈 리스트

    //만약 삭제하려는 값이 헤드면
    else if (head->data == value) { 
        removed = head; //헤드를 지울 노드로 지정
        head = head->link;  //헤드 다음 노드를 헤드로 지정
        free(removed);  //지울 노드 메모리 해제
        return head;  //바꾼 헤드 반환
    }
    
    // 현재 탐색값이 널이 아닐때 반복
    while (removed != NULL) {
        if (removed->data == value) {  //만약 현재 값이 지울 값이면
            pre->link = removed->link;  //지울값의 링크를 앞 노드의 링크로 지정
            free(removed);  //지울 노드 메모리 해체
            return head;  //헤드 반환
        }

        //못찾았을 경우 노드를 이동함
        pre = removed;  //현재 값을 직전 값으로 지정
        removed = removed->link;  //현재 링크를 현재로 지정해서 다음 노드로 넘어감
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

    printf("삭제할 값을 입력하시오: ");
    scanf_s("%d", &value);

    //삭제함수 실행
    head = delete_node(head, value);
    print_list(head);  //다시 출력

    return 0;
}