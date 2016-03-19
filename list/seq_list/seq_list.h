#ifndef SEQ_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ELEM 100


typedef int elem_type;
typedef struct {
	elem_type elem[MAX_ELEM];
	int num_elem;
} seq_list;

/********************************
* aim:       create a new sequential list and initialize it.
* parameter: void.
* return:    a pointer to the new sequential list.
********************************/
seq_list* SeqListInit(void);

/********************************
* aim:       get how many a list's elements.
* parameter: a pointer to the list.
* return:    element numbers.
********************************/
int SeqListLength(seq_list * list);

/********************************
* aim:       get a element by the its index in a list.
* parameter: list:  a pointer to the list.
*			 index: the element's index.
* return:    the element's value.
********************************/
elem_type SeqListGet(seq_list * list, int index);

/********************************
* aim:       get a element's index by the its value in a list.
* parameter: list: a pointer to the list.
*			 elem: the element's value.
* return:    the element's index.
********************************/
int SeqListLocate(seq_list * list, elem_type elem);

/********************************
* aim:       get a element's former element by its value in a list.
* parameter: list: a pointer to the list.
*			 elem: the element's value.
* return:    the former element.
********************************/
elem_type SeqListFormer(seq_list * list, elem_type elem);

/********************************
* aim:       get a element's latter element by its value in a list.
* parameter: list: a pointer to the list.
*			 elem: the element's value.
* return:    the latter element.
********************************/
elem_type SeqListLatter(seq_list * list, elem_type elem);

/********************************
* aim:       insert a element at a known index in a list.
* parameter: list:  a pointer to the list.
*            index: the known index which between 0 to the list's element numbers.
*			 elem:  the element's value which will be inserted.
* return:    void.
********************************/
void SeqListInsert(seq_list * list, int index, elem_type elem);

/********************************
* aim:       delete a element at a known index in a list.
* parameter: list:  a pointer to the list.
*            index: the known index which between 0 to the list's element numbers.
* return:    void.
********************************/
void SeqListRemove(seq_list * list, int index);

/********************************
* aim:       judge a list is empty or not.
* parameter: list: a pointer to the list.
* return:    bool value whether the list is empty or not.
********************************/
bool SeqListEmpty(seq_list * list);

/********************************
* aim:       clear all the elements in a list.
* parameter: list: a pointer to the list.
* return:    void.
********************************/
void SeqListClear(seq_list * list);

/********************************
* aim:       destroy a list.
* parameter: list: a pointer to the list.
* return:    void.
********************************/
void SeqListDestroy(seq_list * list);

/********************************
* aim:       add a new element in a list's tail.
* parameter: list: a pointer to the list.
*            elem: the element's value which will be added.
* return:    void.
********************************/
void SeqListAdd(seq_list * list, elem_type elem);

/********************************
* aim:       delete a  element in a list's tail.
* parameter: list: a pointer to the list.
* return:    void.
********************************/
void SeqListDelete(seq_list * list);
#endif // !SEQ_LIST_H
