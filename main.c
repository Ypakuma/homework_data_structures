#include "tree\seq_binary_tree\seq_binary_tree.h"

int main(void)
{
	seq_binary_tree tree;
	tree = SeqBinaryTreeInit(0, 6);
	SeqBinaryTreeAddChildL(tree, 0, 3);
	SeqBinaryTreeAddChildR(tree, 0, 2);
	SeqBinaryTreeAddChildL(tree, 1, 5);
	SeqBinaryTreeAddChildR(tree, 1, 4);
	SeqBinaryTreeAddChildR(tree, 2, 6);
	SeqBinaryTreeTraverse(tree);

	seq_binary_tree_node * ans;
	ans = SeqBinaryTreeGetChildL(tree, 2);
	ans = SeqBinaryTreeGetChildR(tree, 1);
	
	SeqBinaryTreeClear(tree);
	SeqBinaryTreeDestroy(&tree);
	return 0;
}
