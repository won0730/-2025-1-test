#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s) {
    s->top = -1;
}

int is_empty(StackType *s) {
    return (s->top == -1);
}

int is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "���� ��ȭ ����\n");
        exit(1); 
    }
    else {
        s->data[++(s->top)] = item;
    }
}

element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1); 
    }
    else {
        return s->data[(s->top)--];
    }
}

int main(void)
{
    char str[100];
    StackType s;
    init_stack(&s);
    int i;
    char c;


    printf("���ڿ��� �Է��Ͻÿ�: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    int len = (strlen(str));

    for (i = 0; i < len; i++) {
        c = tolower(str[i]);
        if (isalnum(c)) {
            push(&s, c);
        }
    }
    for (i = 0; i < len; i++) {
        c = tolower(str[i]);
        if (isalnum(c)) {
            if (is_empty(&s) || pop(&s) != c) {
                printf("ȸ���� �ƴմϴ�.\n");
                return 0;
            }
        }
    }
    printf("ȸ�� �Դϴ�.\n");
    return 0;
}
          

