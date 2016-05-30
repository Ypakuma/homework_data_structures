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

//初始化链表
linked_list LinkedListHeadInit(void);

//按权重由小到大，增加边结点
void LinkedListHeadAdd(linked_list list, int out, int in, int weight);

//删除边结点
void LinkedListHeadDelete(linked_list list, linked_node * locat);

//判空
bool LinkedListHeadEmpty(linked_list list);

//销毁
void LinkedListHeadDestroy(linked_list * list);


#endif
