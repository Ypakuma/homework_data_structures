#include "tree\linked_binary_tree\linked_binary_tree_tri.h"

int main(void)
{
	linked_binary_tree tree;
	tree = LinkedBinaryTreeInit(0);

	LinkedBinaryTreeAddChildL(tree, 1);
	LinkedBinaryTreeAddChildR(tree, 2);
	linked_binary_tree_node * pnode = tree->lchild;
	LinkedBinaryTreeAddChildL(pnode, 3);
	pnode = pnode->lchild;
	LinkedBinaryTreeAddChildL(pnode, 7);
	pnode = pnode->lchild;
	LinkedBinaryTreeAddChildL(pnode, 8);
	pnode = tree->lchild;
	LinkedBinaryTreeAddChildR(pnode, 4);
	pnode = pnode->rchild;
	LinkedBinaryTreeAddChildL(pnode, 9);
	pnode = pnode->lchild;
	LinkedBinaryTreeAddChildR(pnode, 10);
	pnode = tree->rchild;
	LinkedBinaryTreeAddChildL(pnode, 5);
	pnode = pnode->lchild;
	LinkedBinaryTreeAddChildR(pnode, 11);
	pnode = pnode->rchild;
	LinkedBinaryTreeAddChildL(pnode, 12);
	pnode = tree->rchild;
	LinkedBinaryTreeAddChildR(pnode, 6);
	pnode = pnode->rchild;
	LinkedBinaryTreeAddChildR(pnode, 13);
	pnode = pnode->rchild;
	LinkedBinaryTreeAddChildR(pnode, 14);

	linked_binary_tree_elemtype * ans;
	ans = LinkedBinaryTreeGetChildL(tree);
	ans = LinkedBinaryTreeGetChildR(tree);

	LinkedBinaryTreeClear(&(tree->lchild));
	LinkedBinaryTreeDestroy(&tree);
	return 0;
}
