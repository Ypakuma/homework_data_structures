#ifndef ADJ_LIST_UNDIR_GRAPH_H
#define ADJ_LIST_UNDIR_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char adj_list_undir_graph_vex_elemtype;

//邻接结点
typedef struct adj_list_undir_graph_adj_s {
	//入结点下标
	int adj_index;
	//边权重
	int weight;
	//结点的下一个邻接点
	struct adj_list_undir_graph_adj_s * next_adj;
} adj_list_undir_graph_adj_node;

//结点
typedef struct adj_list_undir_graph_vex_s {
	//结点值
	adj_list_undir_graph_vex_elemtype elem;
	//结点指向的第一个邻接点
	adj_list_undir_graph_adj_node * first_adj;
} adj_list_undir_graph_vex_node;

typedef struct adj_list_undir_graph_node_s {
	//最大结点数
	int num_vex;
	//已存储结点数
	int len_vex;
	//已存储边数
	int len_edge;
	//结点数组
	adj_list_undir_graph_vex_node * vex;
} * adj_list_undir_graph;


//初始化图，返回图的地址，参数为结点最大个数
adj_list_undir_graph AdjListUndirGraphInit(int num_vex);

//销毁图，参数为指向图的指针（图的地址）
void AdjListUndirGraphDestroy(adj_list_undir_graph * graph);

//输出图的所有结点与边
void AdjListUndirGraphPrint(adj_list_undir_graph graph);

//判断对于输入的下标，对应结点是否存在
bool AdjListUndirGraphVexExist(adj_list_undir_graph graph, int index);

//增加边，参数包括出结点的下标，入结点下标，权重，返回操作成功的布尔值
bool AdjListUndirGraphAddEdge(adj_list_undir_graph graph, int vex1, int vex2, int weight);

//增加结点
bool AdjListUndirGraphAddVex(adj_list_undir_graph graph, adj_list_undir_graph_vex_elemtype elem);




#endif