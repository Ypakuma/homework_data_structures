#ifndef CIR_LIST_CIR_DOUB_H
#define CIR_LIST_CIR_DOUB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "..\seq_list\seq_list.h"

typedef int elem_type;
typedef struct node {
	elem_type elem;
	struct node * next;
	struct node * prior;
} cir_doub_node, *cir_doub_list;

/********************************
* aim:       initialize a list.
* parameter: void.
* return:    the new linked list.
********************************/
cir_doub_list LinkedListCirDoubInit(void);

/********************************
* aim:       judge a list is empty or not.
* parameter: list: the list.
* return:    bool value whether the list is empty or not.
********************************/
bool LinkedListCirDoubEmpty(cir_doub_list list);

/********************************
* aim:       insert a element at a known location's latter location in a list.
* parameter: locat: a pointer to the location.
*			 elem:  the element's value which will be inserted.
* return:    void.
********************************/
void LinkedListCirDoubInsert(cir_doub_node * locat, elem_type elem);

/********************************
* aim:       add a new element in a list by sort.
* parameter: list: the list.
*            elem: the element's value which will be added.
* return:    void.
********************************/
void LinkedListCirDoubAdd(cir_doub_list list, elem_type elem);

/********************************
* aim:       clear all the elements in a list.
* parameter: list: the list.
* return:    void.
********************************/
void LinkedListCirDoubClear(cir_doub_list list);

/********************************
* aim:       destroy a list.
* parameter: list: the list.
* return:    void.
********************************/
void LinkedListCirDoubDestroy(cir_doub_list list);

/********************************
* aim:       delete a element at a known index(from 1) in a list.
* parameter: list:  the list.
*            locat: a pointer to the location.
* return:    void.
********************************/
void LinkedListCirDoubDelete(cir_doub_list list, cir_doub_node * locat);

/********************************
* aim:       get a element by the its index(from 1) in a list.
* parameter: list:  the list.
*			 index: the element's index.
* return:    a pointer to the element.
********************************/
cir_doub_node * LinkedListCirDoubGet(cir_doub_list list, int index);

/********************************
* aim:       get a element's location by the its value in a list.
* parameter: list: the list.
*			 elem: the element's value.
* return:    a pointer to the element.
********************************/
cir_doub_node * LinkedListCirDoubLocate(cir_doub_list list, elem_type elem);

/********************************
* aim:       get how many a list's elements.
* parameter: list: the list.
* return:    element numbers.
********************************/
int LinkedListCirDoubLength(cir_doub_list list);

/********************************
* aim:       concatenate list2 to list1 without sort, and destroy list2.
* parameter: list1_t: one list.
*            list2_t: a pointer to another list.
* return:    void.
********************************/
void LinkedListCirDoubCat(cir_doub_list list1_t, cir_doub_list * list2_t);

/********************************
* aim:       union list2 to list1 by sort, and destroy list2.
* parameter: list1: one list.
*            list2: a pointer to another list.
* return:    void
********************************/
void LinkedListCirDoubUnion(cir_doub_list list1, cir_doub_list * list2);

/********************************
* aim:       restore a sequential list to a linked list which have head node.
* parameter: s_list: a pointer to the sequential list which will be changed.
*            l_list: the linked list.
* return:    void
********************************/
void SeqToLinkedCirDoub(seq_list * s_list, cir_doub_list l_list);

#endif
