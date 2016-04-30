#ifndef LINKED_BINARY_TREE_TRI_H
#define LINKED_BINARY_TREE_TRI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int linked_binary_tree_elemtype;
typedef struct linked_binary_tree_node_s {
	linked_binary_tree_elemtype elem;
	struct linked_binary_tree_node_s * lchild;
	struct linked_binary_tree_node_s * rchild;
	struct linked_binary_tree_node_s * parent;
} linked_binary_tree_node, *linked_binary_tree;

/********************************
* aim:       initialize a binary tree's node, and the function usually be used by other function.
* parameter: node: the tree node which will be initialized.
*            elem: the value of tree's root.
* return:    void.
********************************/
void LinkedBinaryTreeNodeInit(linked_binary_tree_node * node, linked_binary_tree_elemtype elem);

/********************************
* aim:       initialize a binary tree.
* parameter: elem: the value of tree's root.
* return:    the address of binary tree.
********************************/
linked_binary_tree LinkedBinaryTreeInit(linked_binary_tree_elemtype elem);

/********************************
* aim:       add a left child after a tree node.
* parameter: node: the tree node which will have a left child.
*            elem: the value of the child.
* return:    bool value whether the operation is success or not.
********************************/
bool LinkedBinaryTreeAddChildL(linked_binary_tree_node * node, linked_binary_tree_elemtype elem);

/********************************
* aim:       add a right child after a tree node.
* parameter: node: the tree node which will have a right child.
*            elem: the value of the child.
* return:    bool value whether the operation is success or not.
********************************/
bool LinkedBinaryTreeAddChildR(linked_binary_tree_node * node, linked_binary_tree_elemtype elem);

/********************************
* aim:       judge a tree node is leaf or not.
* parameter: node: the tree node.
* return:    bool value whether tree node is leaf or not.
********************************/
bool LinkedBinaryTreeLeaf(linked_binary_tree_node * node);

/********************************
* aim:       get a tree's depth.
* parameter: node: the tree node.
* return:    the number of the tree's depth.
********************************/
int LinkedBinaryTreeGetDepth(linked_binary_tree_node * node);

/********************************
* aim:       get a tree node's right child.
* parameter: node: the tree node.
* return:    a pointer to the node's right child.
********************************/
linked_binary_tree_node * LinkedBinaryTreeGetChildR(linked_binary_tree_node * node);

/********************************
* aim:       get a tree node's left child.
* parameter: node: the tree node.
* return:    a pointer to the node's left child.
********************************/
linked_binary_tree_node * LinkedBinaryTreeGetChildL(linked_binary_tree_node * node);

/********************************
* aim:       get a tree node's parent.
* parameter: node: the tree node.
* return:    a pointer to the node's left child.
********************************/
linked_binary_tree_node * LinkedBinaryTreeGetParent(linked_binary_tree_node * node);

/********************************
* aim:       destroy a tree node and its all subtrees.
* parameter: node: the tree node which will be destroyed.
* return:    void.
********************************/
void LinkedBinaryTreeDestroy(linked_binary_tree_node ** node);

/********************************
* aim:       destroy a tree's all subtrees.
* parameter: node: a pointer to the tree node which will be cleared.
* return:    void.
********************************/
void LinkedBinaryTreeClear(linked_binary_tree_node ** node);

/********************************
* aim:       traverse a tree by pre order(parent -> left child -> right child).
* parameter: tree: the tree.
* return:    void.
********************************/
void LinkedBinaryTreeTraversePLR(linked_binary_tree tree);

/********************************
* aim:       traverse a tree by inner order(left child -> parent -> right child).
* parameter: tree: the tree.
* return:    void.
********************************/
void LinkedBinaryTreeTraverseLPR(linked_binary_tree tree);

/********************************
* aim:       traverse a tree by post order(left child -> right child -> parent).
* parameter: tree: the tree.
* return:    void.
********************************/
void LinkedBinaryTreeTraverseLRP(linked_binary_tree tree);

#endif