#ifndef CIR_LIST_CIR_H
#define CIR_LIST_CIR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "..\seq_list\seq_list.h"

typedef int elem_type;

typedef struct node {
	elem_type elem;
	struct node * next;
} cir_node, *cir_list_t;

/********************************
* aim:       initialize a list.
* parameter: void.
* return:    the tail node of new linked list.
********************************/
cir_list_t LinkedListCirInit(void);

/********************************
* aim:       judge a list is empty or not.
* parameter: list_t: the tail node of list.
* return:    bool value whether the list is empty or not.
********************************/
bool LinkedListCirEmpty(cir_list_t list_t);

/********************************
* aim:       insert a element at a known location's latter location in a list.
* parameter: list_t:  a pointer to the tail node of list.
*            locat:   a pointer to the location.
*			 elem:    the element's value which will be inserted.
* return:    void.
********************************/
void LinkedListCirInsert(cir_list_t * list_t, cir_node * locat, elem_type elem);

/********************************
* aim:       add a new element in a list by sort.
* parameter: list_t: a pointer to the tail node of list.
*            elem:   the element's value which will be added.
* return:    void.
********************************/
void LinkedListCirAdd(cir_list_t * list_t, elem_type elem);

/********************************
* aim:       clear all the elements in a list.
* parameter: list_t: a pointer to the tail node of list.
* return:    void.
********************************/
void LinkedListCirClear(cir_list_t * list_t);

/********************************
* aim:       destroy a list.
* parameter: list_t: the tail node of list.
* return:    void.
********************************/
void LinkedListCirDestroy(cir_list_t list_t);

/********************************
* aim:       get a location's former location in a list.
* parameter: list_t: the list.
*			 locat:  a pointer to the location whose former will be get.
* return:    a pointer to the former location.
********************************/
cir_node * LinkedListCirFormer(cir_list_t list_t, cir_node * locat);

/********************************
* aim:       get a element's latter element by its value in a list.
* parameter: list_t: the list.
*			 elem:   the element's value.
* return:    a pointer to the latter element.
********************************/
cir_node * LinkedListCirLatter(cir_list_t list_t, elem_type elem);

/********************************
* aim:       delete a element at a known index(from 1) in a list.
* parameter: list_t: a pointer to the tail node of list.
*            locat:  a pointer to the location.
* return:    void.
********************************/
void LinkedListCirDelete(cir_list_t * list_t, cir_node * locat);

/********************************
* aim:       get a element by the its index(from 1) in a list.
* parameter: list_t: the list.
*			 index:  the element's index.
* return:    a pointer to the element.
********************************/
cir_node * LinkedListCirGet(cir_list_t list_t, int index);

/********************************
* aim:       get a element's location by the its value in a list.
* parameter: list_t: the list.
*			 elem:   the element's value.
* return:    a pointer to the element.
********************************/
cir_node * LinkedListCirLocate(cir_list_t list_t, elem_type elem);

/********************************
* aim:       get how many a list's elements.
* parameter: list_t: the list.
* return:    element numbers.
********************************/
int LinkedListCirLength(cir_list_t list_t);

/********************************
* aim:       concatenate list2 to list1 without sort, and destroy list2.
* parameter: list1_t: a pointer to one list.
*            list2_t: a pointer to another list.
* return:    void.
********************************/
void LinkedListCirCat(cir_list_t * list1_t, cir_list_t * list2_t);

/********************************
* aim:       union list2 to list1 by sort, and destroy list2.
* parameter: list1_t: a pointer to one list.
*            list2_t: a pointer to another list.
* return:    void
********************************/
void LinkedListCirUnion(cir_list_t * list1_t, cir_list_t * list2_t);

/********************************
* aim:       restore a sequential list to a linked list which have head node.
* parameter: s_list: a pointer to the sequential list which will be changed.
*            l_list: a pointer to the linked list.
* return:    void
********************************/
void SeqToLinkedCir(seq_list * s_list, cir_list_t * l_list_t);

#endif
