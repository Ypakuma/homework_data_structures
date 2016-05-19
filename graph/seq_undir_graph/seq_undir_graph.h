#ifndef SEQ_UNDIR_GRAPH_H
#define SEQ_UNDIR_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char seq_undir_graph_vex_elemtype;

typedef struct seq_undir_graph_vex_s {
	seq_undir_graph_vex_elemtype * elem;
	int num_vex;
	int len;
} *seq_undir_graph_vex;

typedef struct seq_undir_graph_node_s {
	seq_undir_graph_vex vex;
	int **weight;
} *seq_undir_graph;


//初始化图，返回图的地址，参数为结点最大个数
seq_undir_graph SeqUndirGraphInit(int num_vex);

//清空图
void SeqUndirGraphClear(seq_undir_graph graph);

//销毁图，参数为指向图的指针（图的地址）
void SeqUndirGraphDestroy(seq_undir_graph * pgraph);

//输出图的所有结点与边
void SeqUndirGraphPrint(seq_undir_graph graph);

//判断对于输入的下标，对应结点是否存在
bool SeqUndirGraphVexExist(seq_undir_graph graph, int index);

//增加边，参数包括出结点的下标，入结点下标，权重，返回操作成功的布尔值
bool SeqUndirGraphAddEdge(seq_undir_graph graph, int edge1, int edge2, int weight);

//删除边，参数包括出结点的下标，入结点下标，返回操作成功的布尔值
bool SeqUndirGraphDelEdge(seq_undir_graph graph, int edge1, int edge2);

//增加结点
bool SeqUndirGraphAddVex(seq_undir_graph graph, seq_undir_graph_vex_elemtype elem);

//删除结点
bool SeqUndirGraphDelVex(seq_undir_graph graph, int index);

//根据结点下标，求结点度
int SeqUndirGraphDegree(seq_undir_graph graph, int index);

//定位结点，参数为结点元素，返回结点下标，如果元素不存在，返回-1
int SeqUndirGraphLocateVex(seq_undir_graph graph, seq_undir_graph_vex_elemtype elem);

//返回对应下标的值
seq_undir_graph_vex_elemtype SeqUndirGraphGetVex(seq_undir_graph graph, int index);

//返回输入下标的第一个邻接点（adj），返回邻接点的下标
int SeqUndirGraphFirstAdj(seq_undir_graph graph, int index);

//返回输入下标相对于另一个下标的下一个邻接点，返回邻接点的下标
//返回邻接点的下标,如果index不存在，返回-2；如果pre的下一个邻接点不存在，返回-1
int SeqUndirGraphNextAdj(seq_undir_graph graph, int index, int pre);

//深度优先遍历图
void SeqUndirGraphTraverseD(seq_undir_graph graph);

//广度优先遍历图
void SeqUndirGraphTraverseB(seq_undir_graph graph);




#endif