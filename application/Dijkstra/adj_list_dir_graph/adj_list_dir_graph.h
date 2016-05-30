#ifndef ADJ_LIST_DIR_GRAPH_H
#define ADJ_LIST_DIR_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char adj_list_dir_graph_vex_elemtype;

//�ڽӽ��
typedef struct adj_list_dir_graph_adj_s {
	//�����±�
	int adj_index;
	//���ָ����ڽӵ�ıߵ�Ȩ��
	int weight;
	//������һ���ڽӵ�
	struct adj_list_dir_graph_adj_s * next_adj;
} adj_list_dir_graph_adj_node;

//���
typedef struct adj_list_dir_graph_vex_s {
	//���ֵ
	adj_list_dir_graph_vex_elemtype elem;
	//���ָ��ĵ�һ���ڽӵ�
	adj_list_dir_graph_adj_node * first_adj;
} adj_list_dir_graph_vex_node;

typedef struct adj_list_dir_graph_node_s {
	//�������
	int num_vex;
	//�Ѵ洢�����
	int len;
	//�������
	adj_list_dir_graph_vex_node * vex;
} *adj_list_dir_graph;


//��ʼ��ͼ������ͼ�ĵ�ַ������Ϊ���������
adj_list_dir_graph AdjListDirGraphInit(int num_vex);

//���ͼ
void AdjListDirGraphClear(adj_list_dir_graph graph);

//����ͼ������Ϊָ��ͼ��ָ�루ͼ�ĵ�ַ��
void AdjListDirGraphDestroy(adj_list_dir_graph * graph);

//���ͼ�����н�����
void AdjListDirGraphPrint(adj_list_dir_graph graph);

//�ж϶���������±꣬��Ӧ����Ƿ����
bool AdjListDirGraphVexExist(adj_list_dir_graph graph, int index);

//���ӱߣ����������������±꣬�����±꣬Ȩ�أ����ز����ɹ��Ĳ���ֵ
bool AdjListDirGraphAddEdge(adj_list_dir_graph graph, int out, int in, int weight);

//ɾ���ߣ����������������±꣬�����±꣬���ز����ɹ��Ĳ���ֵ
bool AdjListDirGraphDelEdge(adj_list_dir_graph graph, int out, int in);

//���ӽ��
bool AdjListDirGraphAddVex(adj_list_dir_graph graph, adj_list_dir_graph_vex_elemtype elem);

//ɾ�����
bool AdjListDirGraphDelVex(adj_list_dir_graph graph, int index);

//���ݽ���±꣬�������
//�ڽӱ��ʺ������
int AdjListDirGraphIndegree(adj_list_dir_graph graph, int index);

//���ݽ���±꣬�������
int AdjListDirGraphOutdegree(adj_list_dir_graph graph, int index);

//��λ��㣬����Ϊ���Ԫ�أ����ؽ���±꣬���Ԫ�ز����ڣ�����-1
int AdjListDirGraphLocateVex(adj_list_dir_graph graph, adj_list_dir_graph_vex_elemtype elem);

//���ض�Ӧ�±��ֵ
adj_list_dir_graph_vex_elemtype AdjListDirGraphGetVex(adj_list_dir_graph graph, int index);

//���������±�ĵ�һ���ڽӵ㣨adj���������ڽӵ���±�
int AdjListDirGraphFirstAdj(adj_list_dir_graph graph, int index);

//���������±�index�������һ���±�pre����һ���ڽӵ�
//�����ڽӵ���±�,���index�����ڣ�����-2�����pre����һ���ڽӵ㲻���ڣ�����-1
int AdjListDirGraphNextAdj(adj_list_dir_graph graph, int index, int pre);

//������ȱ���ͼ
void AdjListDirGraphTraverseD(adj_list_dir_graph graph);

//������ȱ���ͼ
void AdjListDirGraphTraverseB(adj_list_dir_graph graph);




#endif