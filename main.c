#include "stack\listed_stack\linked_stack.h"

int main(void)
{
	linked_stack stack;
	stack = LinkedStackInit();
	bool ans = LinkedStackEmpty(stack);
	LinkedStackPush(&stack, 12);
	ans = LinkedStackEmpty(stack);

	LinkedStackPush(&stack, 123);
	LinkedStackPush(&stack, 1234);

	elemtype elem = LinkedStackPop(&stack);
	elem = LinkedStackPop(&stack);
	ans = LinkedStackEmpty(stack);
	elem = LinkedStackPop(&stack);
	ans = LinkedStackEmpty(stack);

	LinkedStackPush(&stack, 12);
	LinkedStackPush(&stack, 123);
	LinkedStackPush(&stack, 1234);

	LinkedStackDestroy(&stack);

	return 0;
}
