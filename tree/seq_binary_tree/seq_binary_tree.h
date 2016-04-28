#ifndef SEQ_BINARY_TREE_H
#define SEQ_BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int seq_binary_tree_elemtype;

typedef struct seq_binary_tree_node_s {
	seq_binary_tree_elemtype elem;
	int lchild;
	int rchild;
	int parent;
} seq_binary_tree_node;

typedef struct seq_binary_tree_s {
	int num_node;
	int len;
	seq_binary_tree_node * node;
} *seq_binary_tree;


/********************************
* aim:       initialize a binary tree.
* parameter: elem: the first element's value of the tree.
*            len:  the list's length.
* return:    the address of binary tree.
********************************/
seq_binary_tree SeqBinaryTreeInit(seq_binary_tree_elemtype elem, int len);

/********************************
* aim:       add a left child after a tree's node.
* parameter: tree:   the tree which will add a left child.
*            parent: the index of the parent.
*            elem:   the value of the child.
* return:    bool value whether the operation is success or not.
********************************/
bool SeqBinaryTreeAddChildL(seq_binary_tree tree, int parent, seq_binary_tree_elemtype elem);

/********************************
* aim:       add a right child after a tres node.
* parameter: tree:   the tree which will add a right child.
*            parent: the index of the parent.
*            elem:   the value of the child.
* return:    bool value whether the operation is success or not.
********************************/
bool SeqBinaryTreeAddChildR(seq_binary_tree tree, int parent, seq_binary_tree_elemtype elem);

/********************************
* aim:       judge a index of tree node is exist or not.
* parameter: tree:  the tree.
*            index: the index of the node.
* return:    bool value whether tree node is leaf or not.
********************************/
bool SeqBinaryTreeNodeExist(seq_binary_tree tree, int index);

/********************************
* aim:       judge a tree node is leaf or not.
* parameter: tree:  the tree which contain the node.
*            index: the index of the node.
* return:    bool value whether tree node is leaf or not.
********************************/
bool SeqBinaryTreeLeaf(seq_binary_tree tree, int index);

/********************************
* aim:       get a tree node's right child.
* parameter: tree:  the tree which contain the node.
*            index: the index of the node which will get its right child.
* return:    a index of the node's right child.
********************************/
int SeqBinaryTreeGetChildR(seq_binary_tree tree, int index);

/********************************
* aim:       get a tree node's left child.
* parameter: tree:  the tree which contain the node.
*            index: the index of the node which will get its left child.
* return:    a index of the node's left child.
********************************/
int SeqBinaryTreeGetChildL(seq_binary_tree tree, int index);

/********************************
* aim:       get a tree node's parent.
* parameter: tree:  the tree which contain the node.
*            index: the index of the node which will get its parent.
* return:    a index of  the node's left child.
********************************/
int SeqBinaryTreeGetParent(seq_binary_tree tree, int index);

/********************************
* aim:       destroy a tree node and its all subtrees.
* parameter: tree: the tree which will be destroyed.
* return:    void.
********************************/
void SeqBinaryTreeDestroy(seq_binary_tree tree);

/********************************
* aim:       destroy a tree's all subtrees.
* parameter: node: the tree which will be cleared.
* return:    void.
********************************/
void SeqBinaryTreeClear(seq_binary_tree tree);

/********************************
* aim:       traverse a tree.
* parameter: tree: the tree.
* return:    void.
********************************/
void SeqBinaryTreeTraverse(seq_binary_tree tree);

#endif
