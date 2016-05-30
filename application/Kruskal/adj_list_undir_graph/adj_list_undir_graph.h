#ifndef ADJ_LIST_UNDIR_GRAPH_H
#define ADJ_LIST_UNDIR_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char adj_list_undir_graph_vex_elemtype;

//�ڽӽ��
typedef struct adj_list_undir_graph_adj_s {
	//�����±�
	int adj_index;
	//��Ȩ��
	int weight;
	//������һ���ڽӵ�
	struct adj_list_undir_graph_adj_s * next_adj;
} adj_list_undir_graph_adj_node;

//���
typedef struct adj_list_undir_graph_vex_s {
	//���ֵ
	adj_list_undir_graph_vex_elemtype elem;
	//���ָ��ĵ�һ���ڽӵ�
	adj_list_undir_graph_adj_node * first_adj;
} adj_list_undir_graph_vex_node;

typedef struct adj_list_undir_graph_node_s {
	//�������
	int num_vex;
	//�Ѵ洢�����
	int len_vex;
	//�Ѵ洢����
	int len_edge;
	//�������
	adj_list_undir_graph_vex_node * vex;
} * adj_list_undir_graph;


//��ʼ��ͼ������ͼ�ĵ�ַ������Ϊ���������
adj_list_undir_graph AdjListUndirGraphInit(int num_vex);

//����ͼ������Ϊָ��ͼ��ָ�루ͼ�ĵ�ַ��
void AdjListUndirGraphDestroy(adj_list_undir_graph * graph);

//���ͼ�����н�����
void AdjListUndirGraphPrint(adj_list_undir_graph graph);

//�ж϶���������±꣬��Ӧ����Ƿ����
bool AdjListUndirGraphVexExist(adj_list_undir_graph graph, int index);

//���ӱߣ����������������±꣬�����±꣬Ȩ�أ����ز����ɹ��Ĳ���ֵ
bool AdjListUndirGraphAddEdge(adj_list_undir_graph graph, int vex1, int vex2, int weight);

//���ӽ��
bool AdjListUndirGraphAddVex(adj_list_undir_graph graph, adj_list_undir_graph_vex_elemtype elem);




#endif