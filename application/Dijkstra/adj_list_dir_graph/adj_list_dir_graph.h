#ifndef ADJ_LIST_DIR_GRAPH_H
#define ADJ_LIST_DIR_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char adj_list_dir_graph_vex_elemtype;

//邻接结点
typedef struct adj_list_dir_graph_adj_s {
	//入结点下标
	int adj_index;
	//结点指向该邻接点的边的权重
	int weight;
	//结点的下一个邻接点
	struct adj_list_dir_graph_adj_s * next_adj;
} adj_list_dir_graph_adj_node;

//结点
typedef struct adj_list_dir_graph_vex_s {
	//结点值
	adj_list_dir_graph_vex_elemtype elem;
	//结点指向的第一个邻接点
	adj_list_dir_graph_adj_node * first_adj;
} adj_list_dir_graph_vex_node;

typedef struct adj_list_dir_graph_node_s {
	//最大结点数
	int num_vex;
	//已存储结点数
	int len;
	//结点数组
	adj_list_dir_graph_vex_node * vex;
} *adj_list_dir_graph;


//初始化图，返回图的地址，参数为结点最大个数
adj_list_dir_graph AdjListDirGraphInit(int num_vex);

//清空图
void AdjListDirGraphClear(adj_list_dir_graph graph);

//销毁图，参数为指向图的指针（图的地址）
void AdjListDirGraphDestroy(adj_list_dir_graph * graph);

//输出图的所有结点与边
void AdjListDirGraphPrint(adj_list_dir_graph graph);

//判断对于输入的下标，对应结点是否存在
bool AdjListDirGraphVexExist(adj_list_dir_graph graph, int index);

//增加边，参数包括出结点的下标，入结点下标，权重，返回操作成功的布尔值
bool AdjListDirGraphAddEdge(adj_list_dir_graph graph, int out, int in, int weight);

//删除边，参数包括出结点的下标，入结点下标，返回操作成功的布尔值
bool AdjListDirGraphDelEdge(adj_list_dir_graph graph, int out, int in);

//增加结点
bool AdjListDirGraphAddVex(adj_list_dir_graph graph, adj_list_dir_graph_vex_elemtype elem);

//删除结点
bool AdjListDirGraphDelVex(adj_list_dir_graph graph, int index);

//根据结点下标，求结点入度
//邻接表不适合求入度
int AdjListDirGraphIndegree(adj_list_dir_graph graph, int index);

//根据结点下标，求结点出度
int AdjListDirGraphOutdegree(adj_list_dir_graph graph, int index);

//定位结点，参数为结点元素，返回结点下标，如果元素不存在，返回-1
int AdjListDirGraphLocateVex(adj_list_dir_graph graph, adj_list_dir_graph_vex_elemtype elem);

//返回对应下标的值
adj_list_dir_graph_vex_elemtype AdjListDirGraphGetVex(adj_list_dir_graph graph, int index);

//返回输入下标的第一个邻接点（adj），返回邻接点的下标
int AdjListDirGraphFirstAdj(adj_list_dir_graph graph, int index);

//返回输入下标index相对于另一个下标pre的下一个邻接点
//返回邻接点的下标,如果index不存在，返回-2；如果pre的下一个邻接点不存在，返回-1
int AdjListDirGraphNextAdj(adj_list_dir_graph graph, int index, int pre);

//深度优先遍历图
void AdjListDirGraphTraverseD(adj_list_dir_graph graph);

//广度优先遍历图
void AdjListDirGraphTraverseB(adj_list_dir_graph graph);




#endif