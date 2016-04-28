#include "linked_binary_tree_tri.h"

void LinkedBinaryTreeNodeInit(linked_binary_tree_node * node, linked_binary_tree_elemtype elem)
{
	node->elem = elem;
	node->lchild = NULL;
	node->rchild = NULL;
	node->parent = NULL;
}

linked_binary_tree LinkedBinaryTreeInit(linked_binary_tree_elemtype elem)
{
	linked_binary_tree ptree = (linked_binary_tree) malloc(sizeof(linked_binary_tree_node));
	if (!ptree) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	LinkedBinaryTreeNodeInit(ptree, elem);

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

	LinkedBinaryTreeNodeInit(pchild, elem);
	node->lchild = pchild;
	pchild->parent = node;

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

	LinkedBinaryTreeNodeInit(pchild, elem);
	node->rchild = pchild;
	pchild->parent = node;

	return true;
}

bool LinkedBinaryTreeLeaf(linked_binary_tree_node * node)
{
	return !(node->lchild || node->lchild);
}

int LinkedBinaryTreeGetDepth(linked_binary_tree_node * node)
{
	if (LinkedBinaryTreeLeaf(node))
		return 1;

	int depth_l, depth_r;
	depth_l = LinkedBinaryTreeGetDepth(node->lchild);
	depth_r = LinkedBinaryTreeGetDepth(node->rchild);

	return 1 + (depth_l > depth_r ? depth_l : depth_r);
}

linked_binary_tree_elemtype * LinkedBinaryTreeGetChildR(linked_binary_tree_node * node)
{
	linked_binary_tree_elemtype * pnode = node->rchild;
	if (pnode)
		return pnode;

	printf("NO right child.\n");
	return NULL;
}

linked_binary_tree_elemtype * LinkedBinaryTreeGetChildL(linked_binary_tree_node * node)
{
	linked_binary_tree_elemtype * pnode = node->lchild;
	if (pnode)
		return pnode;

	printf("NO left child.\n");
	return NULL;
}

linked_binary_tree_elemtype * LinkedBinaryTreeGetParent(linked_binary_tree_node * node)
{
	linked_binary_tree_elemtype * pnode = node->parent;
	if (pnode)
		return pnode;

	printf("The node is root.\n");
	return NULL;
}

void LinkedBinaryTreeDestroy(linked_binary_tree_node ** node)
{
	if (!(*node))
		return;

	LinkedBinaryTreeDestroy(&((*node)->lchild));
	LinkedBinaryTreeDestroy(&((*node)->rchild));
	free(*node);

	(*node) = NULL;
}

void LinkedBinaryTreeClear(linked_binary_tree_node ** node)
{
	linked_binary_tree_elemtype elem = (*node)->elem;

	LinkedBinaryTreeDestroy(node);
	(*node) = LinkedBinaryTreeInit(elem);

}

/****the next three functions can edit in the particular locations.****/
void LinkedBinaryTreeTraversePLR(linked_binary_tree tree)
{
	if (tree) {
		/****these codes can edit****/
		printf("%d", tree->elem);
		/****these codes can edit****/
		LinkedBinaryTreeTraversePLR(tree->lchild);
		LinkedBinaryTreeTraversePLR(tree->rchild);
	}
}

void LinkedBinaryTreeTraverseLPR(linked_binary_tree tree)
{
	if (tree) {
		LinkedBinaryTreeTraversePLR(tree->lchild);
		/****these codes can edit****/
		printf("%d", tree->elem);
		/****these codes can edit****/
		LinkedBinaryTreeTraversePLR(tree->rchild);
	}
}

void LinkedBinaryTreeTraverseLRP(linked_binary_tree tree)
{
	if (tree) {
		LinkedBinaryTreeTraversePLR(tree->lchild);
		LinkedBinaryTreeTraversePLR(tree->rchild);
		/****these codes can edit****/
		printf("%d", tree->elem);
		/****these codes can edit****/
	}
}
/****the last three functions can edit in the particular locations.****/
