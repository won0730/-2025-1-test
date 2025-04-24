#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;  
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

typedef struct {
	StackType stack_in;
	StackType stack_out;
} QueueType;

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

void init_queue(QueueType *q) {
	init_stack(&q->stack_in);
	init_stack(&q->stack_out);
}

void enqueue(QueueType *q, element item) {
	push(&q->stack_in, item);
}

element dequeue(QueueType *q) {
	if (!is_empty(&q->stack_out)) {
		return pop(&q->stack_out);
	}
	else {
		if (is_empty(&q->stack_in)) {
			fprintf(stderr, "큐가 비어 있음\n");
			exit(1);
		}
		while (!is_empty(&q->stack_in)) {
			push(&q->stack_out, pop(&q->stack_in));
		}
		return pop(&q->stack_out);
	}
}

int main(void) {
	QueueType q;
	init_queue(&q);
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	enqueue(&q, 40);
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));

	return 0;
}