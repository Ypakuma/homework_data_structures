#include "seq_stack.h"

seq_stack SeqStackInit(int len)
{
	seq_stack pstack = (seq_stack) malloc(sizeof(struct seq_stack_s));
	if (!pstack) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	pstack->top = 0;
	pstack->len = len;
	pstack->elem = (seq_stack_elemtype*) malloc(sizeof(seq_stack_elemtype) * len);
	if (!pstack) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	
	return pstack;
}

bool SeqStackEmpty(seq_stack stack)
{
	if (stack->top == 0)
		return true;
	else
		return false;
}

bool SeqStackFull(seq_stack stack)
{
	if (stack->top == stack->len)
		return true;
	else
		return false;
}

bool SeqStackPush(seq_stack stack, seq_stack_elemtype elem)
{
	if (SeqStackFull(stack)) {
		printf("Full stack.\n");
		return false;
	}

	stack->elem[stack->top] = elem;
	stack->top++;
	return true;
}

seq_stack_elemtype SeqStackPop(seq_stack stack)
{
	if (SeqStackEmpty(stack)) {
		printf("Empty stack.\n");
		return false;
	}

	stack->top--;
	return stack->elem[stack->top];
}

void SeqStackClear(seq_stack stack)
{
	stack->top = 0;
}

void SeqStackDestroy(seq_stack * stack)
{
	if (*stack) {
		free((*stack)->elem);
		free(*stack);
		(*stack) = NULL;
	}
}
