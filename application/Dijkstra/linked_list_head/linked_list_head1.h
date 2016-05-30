#ifndef LINKED_LIST_HEAD_H
#define LINKED_LIST_HEAD_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct linked_list_head_node_s{
	int out;
	int in;
	int weight;
	struct linked_list_head_node_s * next_path;
} linked_node,  *linked_list;

//��ʼ������
linked_list LinkedListHeadInit(void);

//��Ȩ����С�������ӱ߽��
void LinkedListHeadAdd(linked_list list, int out, int in, int weight);

//ɾ���߽��
void LinkedListHeadDelete(linked_list list, linked_node * locat);

//�п�
bool LinkedListHeadEmpty(linked_list list);

//����
void LinkedListHeadDestroy(linked_list * list);


#endif
