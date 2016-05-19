#ifndef SEQ_DIR_GRAPH_H
#define SEQ_DIR_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char seq_dir_graph_vex_elemtype;

typedef struct seq_dir_graph_vex_s {
	seq_dir_graph_vex_elemtype * elem;
	int num_vex;
	int len;
} *seq_dir_graph_vex;

typedef struct seq_dir_graph_node_s {
	seq_dir_graph_vex vex;
	int **weight;
} *seq_dir_graph;


//��ʼ��ͼ������ͼ�ĵ�ַ������Ϊ���������
seq_dir_graph SeqDirGraphInit(int num_vex);

//���ͼ
void SeqDirGraphClear(seq_dir_graph graph);

//����ͼ������Ϊָ��ͼ��ָ�루ͼ�ĵ�ַ��
void SeqDirGraphDestroy(seq_dir_graph * graph);

//���ͼ�����н�����
void SeqDirGraphPrint(seq_dir_graph graph);

//�ж϶���������±꣬��Ӧ����Ƿ����
bool SeqDirGraphVexExist(seq_dir_graph graph, int index);

//���ӱߣ����������������±꣬�����±꣬Ȩ�أ����ز����ɹ��Ĳ���ֵ
bool SeqDirGraphAddEdge(seq_dir_graph graph, int out, int in, int weight);

//ɾ���ߣ����������������±꣬�����±꣬���ز����ɹ��Ĳ���ֵ
bool SeqDirGraphDelEdge(seq_dir_graph graph, int out, int in);

//���ӽ��
bool SeqDirGraphAddVex(seq_dir_graph graph, seq_dir_graph_vex_elemtype elem);

//ɾ�����
bool SeqDirGraphDelVex(seq_dir_graph graph, int index);

//���ݽ���±꣬�������
int SeqDirGraphIndegree(seq_dir_graph graph, int index);

//���ݽ���±꣬�������
int SeqDirGraphOutdegree(seq_dir_graph graph, int index);

//��λ��㣬����Ϊ���Ԫ�أ����ؽ���±꣬���Ԫ�ز����ڣ�����-1
int SeqDirGraphLocateVex(seq_dir_graph graph, seq_dir_graph_vex_elemtype elem);

//���ض�Ӧ�±��ֵ
seq_dir_graph_vex_elemtype SeqDirGraphGetVex(seq_dir_graph graph, int index);

//���������±�ĵ�һ���ڽӵ㣨adj���������ڽӵ���±�
int SeqDirGraphFirstAdj(seq_dir_graph graph, int index);

//���������±�index�������һ���±�pre����һ���ڽӵ�
//�����ڽӵ���±�,���index�����ڣ�����-2�����pre����һ���ڽӵ㲻���ڣ�����-1
int SeqDirGraphNextAdj(seq_dir_graph graph, int index, int pre);

//������ȱ���ͼ
void SeqDirGraphTraverseD(seq_dir_graph graph);

//������ȱ���ͼ
void SeqDirGraphTraverseB(seq_dir_graph graph);




#endif