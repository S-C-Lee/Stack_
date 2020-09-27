#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int data;
	struct Node* next;
}Node;
typedef struct {
	Node* top;
}stack;
push(stack* stack, int data)
{
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = stack->top;
	stack->top = node;
}
int pop(stack* stack)
{
	Node* node = stack->top;
	int res = node->data;
	stack->top = node->next;
	free(node);
	return res;
}
showall(stack* stack)
{
	Node* cur = stack->top;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}
Freeall(stack* stack)
{
	Node* Freeall = stack->top;
	while (Freeall != NULL)
	{
		free(Freeall);
		Freeall = Freeall->next;
	}
}
main()
{
	stack stack;
	stack.top = NULL;
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);
	push(&stack, 6);
	pop(&stack);
	showall(&stack);
	Freeall(&stack);
}