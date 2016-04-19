#ifndef LINKED_BINARY_TREE_H
#define LINKED_BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "..\..\stack\seq_stack\seq_stack.h"

typedef int linked_binary_tree_elemtype;
typedef struct linked_binary_tree_node_s {
	linked_binary_tree_elemtype elem;
	struct linked_binary_tree_node_s * lchild;
	struct linked_binary_tree_node_s * rchild;
} linked_binary_tree_node, *linked_binary_tree;

typedef linked_binary_tree_node* linked_stack_elemtype;

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
* aim:       judge a tree node is empty or not.
* parameter: node: the tree node.
* return:    bool value whether tree node is empty or not.
********************************/
bool LinkedBinaryTreeEmpty(linked_binary_tree_node * node);

/********************************
* aim:       judge a tree node is leaf or not.
* parameter: node: the tree node.
* return:    bool value whether tree node is leaf or not.
********************************/
bool LinkedBinaryTreeLeaf(linked_binary_tree_node * node);

/********************************
* aim:       get a tree node's right child.
* parameter: node: the tree node.
* return:    the value of the node's right child.
********************************/
linked_binary_tree_elemtype LinkedBinaryGetChildR(linked_binary_tree_node * node);

/********************************
* aim:       get a tree node's left child.
* parameter: node: the tree node.
* return:    the value of the node's left child.
********************************/
linked_binary_tree_elemtype LinkedBinaryGetChildL(linked_binary_tree_node * node);

/********************************
* aim:       add a right child after a tree node.
* parameter: node: the tree node which will have a right child.
*            elem: the value of the child.
* return:    bool value whether the operation is success or not.
********************************/
void LinkedBinaryTreeChangeValue(linked_binary_tree_node * node, linked_binary_tree_elemtype elem);

/********************************
* aim:       destroy a tree node and its all subtrees.
* parameter: node: the tree node which will be destroyed.
* return:    void.
********************************/
void LinkedBinaryTreeDestroy(linked_binary_tree_node ** node);

/********************************
* aim:       destroy a tree's all subtrees.
* parameter: node: the tree node which will be cleared.
* return:    void.
********************************/
void LinkedBinaryTreeClear(linked_binary_tree_node * node);

/********************************
* aim:       traverse a tree by pre order(parents -> left child -> right child).
* parameter: node: the tree node which will be cleared.
* return:    void.
********************************/
void LinkedBinaryTreeTraversePLR(linked_binary_tree tree);
#endif