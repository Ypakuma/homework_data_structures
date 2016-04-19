#include "linked_binary_tree.h"

void LinkedBinaryTreeNodeInit(linked_binary_tree_node * node, linked_binary_tree_elemtype elem)
{
	node->elem = elem;
	node->lchild = NULL;
	node->rchild = NULL;
}

linked_binary_tree LinkedBinaryTreeInit(linked_binary_tree_elemtype elem)
{
	linked_binary_tree ptree = (linked_binary_tree) malloc(sizeof(linked_binary_tree_node));
	if (!ptree) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	LinkedBinaryTreeInit(ptree, elem);

	return ptree;
}

bool LinkedBinaryTreeAddChildL(linked_binary_tree_node * node, linked_binary_tree_elemtype elem)
{
	if (node->lchild) {
		printf("The node has already had a left child.\n");
		return false;
	}

	linked_binary_tree_node * pchild = (linked_binary_tree_node *) malloc(sizeof(linked_binary_tree_node));
	if (!pchild) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	LinkedBinaryTreeInit(pchild, elem);
	node->lchild = pchild;

	return true;
}

bool LinkedBinaryTreeAddChildR(linked_binary_tree_node * node, linked_binary_tree_elemtype elem)
{
	if (node->rchild) {
		printf("The node has already had a right child.\n");
		return false;
	}

	linked_binary_tree_node * pchild = (linked_binary_tree_node *) malloc(sizeof(linked_binary_tree_node));
	if (!pchild) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	LinkedBinaryTreeInit(pchild, elem);
	node->rchild = pchild;

	return true;
}

bool LinkedBinaryTreeEmpty(linked_binary_tree_node * node)
{
	return node;
}

bool LinkedBinaryTreeLeaf(linked_binary_tree_node * node)
{
	return !(node->lchild || node->lchild);
}

linked_binary_tree_elemtype LinkedBinaryGetChildR(linked_binary_tree_node * node)
{
	if (node->rchild)
		return node->rchild->elem;

	printf("NO right child.\n");
	exit(0);
}

linked_binary_tree_elemtype LinkedBinaryGetChildL(linked_binary_tree_node * node)
{
	if (node->lchild)
		return node->lchild->elem;

	printf("NO left child.\n");
	exit(0);
}

void LinkedBinaryTreeChangeValue(linked_binary_tree_node * node, linked_binary_tree_elemtype elem)
{
	node->elem = elem;
}

void LinkedBinaryTreeDestroy(linked_binary_tree_node ** node)
{
	if (LinkedBinaryTreeEmpty(*node))
		return;

	if (LinkedBinaryTreeLeaf(*node)) {
		free(*node);
		(*node) = NULL;
	}
	else {
		LinkedBinaryTreeDestroy(&((*node)->lchild));
		LinkedBinaryTreeDestroy(&((*node)->rchild));
	}
}

void LinkedBinaryTreeClear(linked_binary_tree_node * node)
{
	linked_binary_tree_elemtype elem = node->elem;

	LinkedBinaryTreeDestroy(&node);
	node = LinkedBinaryTreeInit(elem);
}

void LinkedBinaryTreeTraversePLR(linked_binary_tree tree)
{
	linked_binary_tree_node * pnode = tree;
	seq_stack stack;

	while (1) {
		printf("%d\n", pnode->elem);
		if (!LinkedBinaryTreeLeaf(tree)) {
			SeqStackPush(stack, &pnode);
			pnode = pnode->lchild;
		}
		else {
			pnode = (SeqStackPop(stack))->;
		}
	}
}
