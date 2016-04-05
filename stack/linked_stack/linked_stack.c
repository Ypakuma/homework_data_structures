#include "linked_stack.h"

linked_stack LinkedStackInit(void)
{
	return NULL;
}

bool LinkedStackEmpty(linked_stack stack)
{
	return !stack;
}

bool LinkedStackPush(linked_stack * stack, linked_stack_elemtype elem)
{
	struct linked_stack_node_s * pnode = (struct linked_stack_node_s *)malloc(sizeof(struct linked_stack_node_s));

	pnode->elem = elem;
	pnode->next = (*stack);
	(*stack) = pnode;
}

linked_stack_elemtype LinkedStackPop(linked_stack * stack)
{
	if (LinkedStackEmpty(*stack)) {
		printf("Empty stack.\n");
		exit(0);
	}

	struct linked_stack_node_s * pnode = (*stack);
	linked_stack_elemtype elem = pnode->elem;
	(*stack) = pnode->next;

	free(pnode);
	return elem;
}

void LinkedStackDestroy(linked_stack * stack)
{
	while (*stack) {
		struct linked_stack_node_s * pnode = (*stack);
		(*stack) = (*stack)->next;
		free(pnode);
	}
	(*stack) = NULL;
}
