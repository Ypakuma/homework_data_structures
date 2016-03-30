#include "seq_stack.h"

seq_stack SeqStackInit(void)
{
	seq_stack pstack = (seq_stack) malloc(sizeof(struct stack));

	pstack->top = 0;
	pstack->len = N;
	pstack->elem = (elemtype*) malloc(sizeof(elemtype) * pstack->len);
	
	return pstack;
}

bool SeqStackEmpty(seq_stack stack)
{
	return stack->top == 0 ? true : false;
}

bool SeqStackFull(seq_stack stack)
{
	return stack->top == stack->len ? true : false;
}

bool SeqStackPush(seq_stack stack, elemtype elem)
{
	if (SeqStackFull(stack)) {
		printf("Full stack.\n");
		return false;
	}

	stack->elem[stack->top] = elem;
	stack->top++;
	return true;
}

elemtype SeqStackPop(seq_stack stack)
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
