#include "linked_stack.h"

linked_stack LinkedStackInit(void)
{
	return NULL;
}

bool LinkedStackEmpty(linked_stack stack)
{
	return !stack;
}

bool LinkedStackPush(linked_stack * stack, elemtype elem)
{
	struct stack_node * pnode = (struct stack_node *)malloc(sizeof(struct stack_node));

	pnode->elem = elem;
	pnode->next = (*stack);
	(*stack) = pnode;
}

elemtype LinkedStackPop(linked_stack * stack)
{
	if (LinkedStackEmpty(*stack)) {
		printf("Empty stack.\n");
		exit(0);
	}

	struct stack_node * pnode = (*stack);
	elemtype elem = pnode->elem;
	(*stack) = pnode->next;

	free(pnode);
	return elem;
}

void LinkedStackDestroy(linked_stack * stack)
{
	while (*stack) {
		struct stack_node * pnode = (*stack);
		(*stack) = (*stack)->next;
		free(pnode);
	}
	(*stack) = NULL;
}
