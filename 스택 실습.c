#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;  //구조체 element(배열) 정의
typedef struct {
    element data[MAX_STACK_SIZE]; //데이터 저장 배열 
    int top; //가장 최근에 넣은 데이터
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s) {
    s->top = -1;  // top을 -1로 설정하여 빈스택 상태로 만듬
}

// 스택이 비어있는지 확인하는 함수
int is_empty(StackType* s) {
    return (s->top == -1);  //top이 -1 이면 스택이 빈 상태
}

// 스택이 가득 찼는지 확인하는 함수
int is_full(StackType* s) {
    return (s->top == (MAX_STACK_SIZE - 1));  
}

// 스택에 요소를 추가하는 함수
void push(StackType* s, element item) {
    if (is_full(s)) {                        
        fprintf(stderr, "스택 포화 에러\n");  //스택이 꽉찼을 때 스택 포화에러
        exit(1); // 오류 발생 시 프로그램 종료
    }
    else {
        s->data[++(s->top)] = item;  //스택이 꽉차지 않았으면 top을 증가시키고 데이터를 저장
    }
}

// 스택에서 요소를 제거하고 반환하는 함수
element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");  //스택이 비어있을 때 스택 공백 에러
        exit(1); // 오류 발생 시 프로그램 종료
    }
    else {
        return s->data[(s->top)--];  //스택이 비어있지 않으면 top 감소시킴
    }
}

int main(void) {
    StackType s;

    init_stack(&s);  //스택 초기화

    push(&s, 1);  //1 저장, top=0
    push(&s, 2);  //2 저장, top=1
    push(&s, 3);  //3 저장, top=2

    printf("%d\n", pop(&s)); 
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));  //가장 상단의 데이터를 출력 후 삭제

    return 0; //main함수의 return을 명시적으로 추가.
}