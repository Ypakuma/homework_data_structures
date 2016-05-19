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


//��ʼ��ͼ������ͼ�ĵ�ַ������Ϊ���������
seq_undir_graph SeqUndirGraphInit(int num_vex);

//���ͼ
void SeqUndirGraphClear(seq_undir_graph graph);

//����ͼ������Ϊָ��ͼ��ָ�루ͼ�ĵ�ַ��
void SeqUndirGraphDestroy(seq_undir_graph * pgraph);

//���ͼ�����н�����
void SeqUndirGraphPrint(seq_undir_graph graph);

//�ж϶���������±꣬��Ӧ����Ƿ����
bool SeqUndirGraphVexExist(seq_undir_graph graph, int index);

//���ӱߣ����������������±꣬�����±꣬Ȩ�أ����ز����ɹ��Ĳ���ֵ
bool SeqUndirGraphAddEdge(seq_undir_graph graph, int edge1, int edge2, int weight);

//ɾ���ߣ����������������±꣬�����±꣬���ز����ɹ��Ĳ���ֵ
bool SeqUndirGraphDelEdge(seq_undir_graph graph, int edge1, int edge2);

//���ӽ��
bool SeqUndirGraphAddVex(seq_undir_graph graph, seq_undir_graph_vex_elemtype elem);

//ɾ�����
bool SeqUndirGraphDelVex(seq_undir_graph graph, int index);

//���ݽ���±꣬�����
int SeqUndirGraphDegree(seq_undir_graph graph, int index);

//��λ��㣬����Ϊ���Ԫ�أ����ؽ���±꣬���Ԫ�ز����ڣ�����-1
int SeqUndirGraphLocateVex(seq_undir_graph graph, seq_undir_graph_vex_elemtype elem);

//���ض�Ӧ�±��ֵ
seq_undir_graph_vex_elemtype SeqUndirGraphGetVex(seq_undir_graph graph, int index);

//���������±�ĵ�һ���ڽӵ㣨adj���������ڽӵ���±�
int SeqUndirGraphFirstAdj(seq_undir_graph graph, int index);

//���������±��������һ���±����һ���ڽӵ㣬�����ڽӵ���±�
//�����ڽӵ���±�,���index�����ڣ�����-2�����pre����һ���ڽӵ㲻���ڣ�����-1
int SeqUndirGraphNextAdj(seq_undir_graph graph, int index, int pre);

//������ȱ���ͼ
void SeqUndirGraphTraverseD(seq_undir_graph graph);

//������ȱ���ͼ
void SeqUndirGraphTraverseB(seq_undir_graph graph);




#endif