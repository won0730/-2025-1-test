#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;  //����ü element(�迭) ����
typedef struct {
    element data[MAX_STACK_SIZE]; //������ ���� �迭 
    int top; //���� �ֱٿ� ���� ������
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s) {
    s->top = -1;  // top�� -1�� �����Ͽ� ���� ���·� ����
}

// ������ ����ִ��� Ȯ���ϴ� �Լ�
int is_empty(StackType* s) {
    return (s->top == -1);  //top�� -1 �̸� ������ �� ����
}

// ������ ���� á���� Ȯ���ϴ� �Լ�
int is_full(StackType* s) {
    return (s->top == (MAX_STACK_SIZE - 1));  
}

// ���ÿ� ��Ҹ� �߰��ϴ� �Լ�
void push(StackType* s, element item) {
    if (is_full(s)) {                        
        fprintf(stderr, "���� ��ȭ ����\n");  //������ ��á�� �� ���� ��ȭ����
        exit(1); // ���� �߻� �� ���α׷� ����
    }
    else {
        s->data[++(s->top)] = item;  //������ ������ �ʾ����� top�� ������Ű�� �����͸� ����
    }
}

// ���ÿ��� ��Ҹ� �����ϰ� ��ȯ�ϴ� �Լ�
element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");  //������ ������� �� ���� ���� ����
        exit(1); // ���� �߻� �� ���α׷� ����
    }
    else {
        return s->data[(s->top)--];  //������ ������� ������ top ���ҽ�Ŵ
    }
}

int main(void) {
    StackType s;

    init_stack(&s);  //���� �ʱ�ȭ

    push(&s, 1);  //1 ����, top=0
    push(&s, 2);  //2 ����, top=1
    push(&s, 3);  //3 ����, top=2

    printf("%d\n", pop(&s)); 
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));  //���� ����� �����͸� ��� �� ����

    return 0; //main�Լ��� return�� ��������� �߰�.
}