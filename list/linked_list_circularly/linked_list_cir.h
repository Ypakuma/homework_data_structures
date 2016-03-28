#ifndef LINKED_LIST_CIR_H
#define LINKED_LIST_CIR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int elem_type;

typedef struct node {
	elem_type elem;
	struct node * next;
} cir_node;

typedef struct list{
	cir_node * head;
	cir_node * tail;
} * cir_list;

/********************************
* aim:       initialize a list.
* parameter: void.
* return:    the new linked list.
********************************/
cir_list LinkedListCirInit(void);

/********************************
* aim:       judge a list is empty or not.
* parameter: list: the list.
* return:    bool value whether the list is empty or not.
********************************/
bool LinkedListCirEmpty(cir_list list);

/********************************
* aim:       insert a element at a known location's latter location in a list.
* parameter: list:  the list.
*            locat: a pointer to the location.
*			 elem:  the element's value which will be inserted.
* return:    void.
********************************/
void LinkedListCirInsert(cir_list list, cir_node * locat, elem_type elem);

/********************************
* aim:       add a new element in a list by sort.
* parameter: list: the list.
*            elem: the element's value which will be added.
* return:    void.
********************************/
void LinkedListCirAdd(cir_list list, elem_type elem);

/********************************
* aim:       clear all the elements in a list.
* parameter: list: the list.
* return:    void.
********************************/
void LinkedListCirClear(cir_list list);

/********************************
* aim:       destroy a list.
* parameter: list: the list.
* return:    void.
********************************/
void LinkedListCirDestroy(cir_list list);

#endif
