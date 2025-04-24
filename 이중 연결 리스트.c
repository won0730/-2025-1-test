#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode* llink;  //링크 두개 만들어야함 
	struct DlistNode* rlink;
}DlistNode;

// 이중 연결 리스트를 초기화
void init(DlistNode* phead)
{
	phead->llink = phead;  
	phead->rlink = phead;  //헤드노드 하나만 존재 각각의 링크가 자기 자신을 가르키도록 함
}

//삽입연산
void dinsert(DlistNode* before, element data) {
	DlistNode* newnode = (DlistNode*)malloc(sizeof(DlistNode));  //새로운 노드 동적할당
	newnode->data = data;  //새 노드에 데이터 저장

	newnode->llink = before; //새 노드의 왼쪽 링크를 앞 노드로 지정
	newnode->rlink = before->rlink;  //새 노드의 오른쪽 링크를 앞 노드의 오른쪽 링크로 지정(헤드노드를 가르키는 링크)

	before->rlink->llink = newnode; //앞 노드가 원래 가르키던 노드(헤더노드)의 왼쪽 링크를 새 노드로 지정
	before->rlink = newnode;  //앞 노드의 오른쪽 링크를 새노드로 지정
}
//삭제연산
void ddelete(DlistNode* head, DlistNode* removed) {
	if (removed == head) // 삭제할 노드가 헤더노드라면
		return;  //삭제하지 않음

	//삭제할 노드의 왼쪽 링크가 가르키는 노드의 오른쪽 링크를 삭제노드 오른쪽 노드로 지정(뛰어넘는것)
	removed->llink->rlink = removed->rlink;  
	//마찬가지
	removed->rlink->llink = removed->llink;

	free(removed);  //메모리 해제
}

//출력 함수
void print_dlist(DlistNode* phead)
{
	DlistNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) { //헤드노드의 오른쪽 링크무터 이동(헤드노드로 다시 돌아올때 까지)
		printf("<-| |%d| |-> ", p->data); //데이터 값 출력
	}
	printf("\n"); //줄바꿈
}

//추가삭제 한단계씩 출력
int main(void)
{
	DlistNode* head = (DlistNode*)malloc(sizeof(DlistNode));  //더미노드이기 때문에 메인함수에서도 동적할당
	init(head); //초기화
	printf("추가 단계\n");
	for (int i = 0; i < 5; i++) {
		// 헤드 노드의 오른쪽에 삽입(순서대로 오른쪽에 삽입하는게 아니라 헤드노드의 오른쪽이기때문에 출력하면 순서가 반대)
		dinsert(head, i);
		print_dlist(head);
	}
	printf("\n삭제 단계\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);  //메모리 해제
	return 0;
}