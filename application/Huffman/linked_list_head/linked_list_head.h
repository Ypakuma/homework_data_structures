#ifndef LINKED_LIST_HEAD_H
#define LINKED_LIST_HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int linked_list_head_elemtype;
typedef struct linked_list_head_node_s{
	linked_list_head_elemtype elem;
	struct linked_list_head_node_s * next;
} linked_node,  *linked_list;

/********************************
* aim:       initialize a list.
* parameter: void.
* return:    a the new linked list.
********************************/
linked_list LinkedListHeadInit(void);

/********************************
* aim:       get a location's former location in a list.
* parameter: list:  the list.
*			 locat: a pointer to the location whose former will be get.
* return:    a pointer to the former location.
********************************/
linked_node * LinkedListHeadFormer(linked_list list, linked_node * locat);

/********************************
* aim:       insert a element at a known location's latter location in a list.
* parameter: locat: a pointer to the location.
*			 elem:  the element's value which will be inserted.
* return:    void.
********************************/
void LinkedListHeadInsert(linked_node * locat, linked_list_head_elemtype elem);

/********************************
* aim:       delete a element at a known location in a list.
* parameter: list:  the list.
*            locat: a pointer to the location.
* return:    void.
********************************/
void LinkedListHeadDelete(linked_list list, linked_node * locat);

/********************************
* aim:       judge a list is empty or not.
* parameter: list: the list.
* return:    bool value whether the list is empty or not.
********************************/
bool LinkedListHeadEmpty(linked_list list);

/********************************
* aim:       clear all the elements in a list.
* parameter: list: the list.
* return:    void.
********************************/
void LinkedListHeadClear(linked_list list);

/********************************
* aim:       destroy a list.
* parameter: list: the list.
* return:    void.
********************************/
void LinkedListHeadDestroy(linked_list * list);

/********************************
* aim:       add a new element in a list by sort.
* parameter: list: the list.
*            elem: the element's value which will be added.
* return:    void.
********************************/
void LinkedListHeadAdd(linked_list list, linked_list_head_elemtype elem);

#endif
