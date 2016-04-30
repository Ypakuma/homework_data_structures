#include "seq_binary_tree.h"

seq_binary_tree SeqBinaryTreeInit(seq_binary_tree_elemtype elem, int len)
{
	seq_binary_tree ptree = (seq_binary_tree) malloc(sizeof(struct seq_binary_tree_s));
	if (!ptree) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	ptree->node = (seq_binary_tree_node*) malloc(len * sizeof(seq_binary_tree_node));
	if (!(ptree->node)) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	ptree->node[0].elem = elem;
	ptree->node[0].lchild = -1;
	ptree->node[0].rchild = -1;
	ptree->node[0].parent = -1;
	ptree->len = len;
	ptree->num_node = 1;

	return ptree;
}

bool SeqBinaryTreeAddChildL(seq_binary_tree tree, int index_parent, seq_binary_tree_elemtype elem)
{
	if (tree->num_node == tree->len) {
		printf("The tree is full.\n");
		return false;
	}
	if (!SeqBinaryTreeNodeExist(tree, index_parent))
		return false;
	if (tree->node[index_parent].lchild != -1) {
		printf("The node has already had a left child.\n");
		return false;
	}

	int index_child = tree->num_node;
	tree->node[index_child].elem = elem;
	tree->node[index_child].lchild = -1;
	tree->node[index_child].rchild = -1;
	tree->node[index_child].parent = index_parent;

	tree->node[index_parent].lchild = index_child;

	(tree->num_node)++;

	return true;
}

bool SeqBinaryTreeAddChildR(seq_binary_tree tree, int index_parent, seq_binary_tree_elemtype elem)
{
	if (tree->num_node == tree->len) {
		printf("The tree is full.\n");
		return false;
	}
	if (!SeqBinaryTreeNodeExist(tree, index_parent))
		return false;
	if (tree->node[index_parent].rchild != -1) {
		printf("The node has already had a right child.\n");
		return false;
	}

	int index_child = tree->num_node;
	tree->node[index_child].elem = elem;
	tree->node[index_child].lchild = -1;
	tree->node[index_child].rchild = -1;
	tree->node[index_child].parent = index_parent;

	tree->node[index_parent].rchild = index_child;

	(tree->num_node)++;

	return true;
}

bool SeqBinaryTreeNodeExist(seq_binary_tree tree, int index)
{
	if (index >= tree->num_node) {
		printf("The node is not exist.\n");
		return false;
	}
	return true;
}

bool SeqBinaryTreeLeaf(seq_binary_tree tree, int index)
{
	if (!SeqBinaryTreeNodeExist(tree, index))
		return false;
	if ((tree->node[index].lchild == -1) && (tree->node[index].lchild == -1))
		return true;
	
	return false;
}

int SeqBinaryTreeGetChildR(seq_binary_tree tree, int index)
{
	if (!SeqBinaryTreeNodeExist(tree, index))
		return false;
	
	int index_child = tree->node[index].rchild;
	if (index_child == -1) {
		printf("The node don't have right child.\n");
	}

	return index_child;
}

int SeqBinaryTreeGetChildL(seq_binary_tree tree, int index)
{
	if (!SeqBinaryTreeNodeExist(tree, index))
		return false;

	int index_child = tree->node[index].lchild;
	if (index_child == -1) {
		printf("The node don't have right child.\n");
	}

	return index_child;
}

int SeqBinaryTreeGetParent(seq_binary_tree tree, int index)
{
	if (!SeqBinaryTreeNodeExist(tree, index))
		return false;

	int index_parent = tree->node[index].parent;
	if (index_parent == -1) {
		printf("The node is tree's root.\n");
	}

	return index_parent;
}

void SeqBinaryTreeDestroy(seq_binary_tree *ptree)
{
	free((*ptree)->node);
	free(*ptree);
	(*ptree) = NULL;
}

void SeqBinaryTreeClear(seq_binary_tree tree)
{
	tree->node[0].lchild = -1;
	tree->node[0].rchild = -1;
	tree->num_node = 1;
}

void SeqBinaryTreeTraverse(seq_binary_tree tree)
{
	int len = tree->len;
	for (int i = 0; i < len; i++)
	{
		/****these codes can edit****/
		printf("%d", tree->node[i].elem);
		/****these codes can edit****/
	}
}
