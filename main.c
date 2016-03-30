#include "stack\seq_stack\seq_stack.h"

int main(void)
{
	seq_stack stack;
	stack = SeqStackInit();
	bool ans;
	ans = SeqStackEmpty(stack);
	SeqStackPush(stack, 1);
	ans = SeqStackEmpty(stack);
	SeqStackPush(stack, 2);
	SeqStackPush(stack, 3);
	SeqStackPush(stack, 4);
	SeqStackPush(stack, 5);
	SeqStackPush(stack, 6);
	SeqStackPush(stack, 7);
	SeqStackPush(stack, 8);
	SeqStackPush(stack, 9);
	SeqStackPush(stack, 10);
	ans = SeqStackFull(stack);


	int a;
	a = SeqStackPop(stack);
	ans = SeqStackFull(stack);
	a = SeqStackPop(stack);
	a = SeqStackPop(stack);


	SeqStackClear(stack);
	ans = SeqStackEmpty(stack);

	SeqStackDestroy(&stack);

	return 0;
}
