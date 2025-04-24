#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* next;
} ListNode;

//새노드 생성 동적할당
ListNode* create_node(element data) {
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) {
		fprintf(stderr, "메모리 할당 오류\n");
		exit(1);
	}
	new_node->data = data;  //새 노드에 값저장
	new_node->next = NULL;  //새 노드의 링크를 널로 지정
	return new_node;  //반환
}

ListNode* insert_first(ListNode* head, element data) {
	//위에 새 노드 생성 함수 만들었기 때문에 동적할당 할 필요 없음
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

//리스트에서 찾는 함수
ListNode* search_list(ListNode* head, element x) {
	ListNode* current = head; //현재값의 초기값을 헤드로 지정(헤드부터 이동하면서 찾음)
	while (current != NULL) {  //현재 값이 널이 아닐때
		if (current->data == x) {  //만약 값을 찾으면
			return current;  //현재 노드 반환
		}
		current = current->next;  //다음 노드로 이동
	}
	return NULL;  //아예 못찾으면 널 반환
}

int main(void) {
	ListNode* head = NULL;

	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);
	if (search_list(head, 30) != NULL)  //30을 찾는데 반환값이 널값이 아니면 찾음
		printf("리스트에서 30을 찾았습니다. \n");
	else
		printf("리스트에서 30을 찾지 못했습니다. \n");
	return 0;
}