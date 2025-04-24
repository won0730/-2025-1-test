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
        fprintf(stderr, "스택 포화 에러\n");
        exit(1); 
    }
    else {
        s->data[++(s->top)] = item;
    }
}

element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
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


    printf("문자열을 입력하시오: ");
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
                printf("회문이 아닙니다.\n");
                return 0;
            }
        }
    }
    printf("회문 입니다.\n");
    return 0;
}
          

