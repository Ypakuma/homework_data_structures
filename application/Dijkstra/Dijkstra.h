#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "adj_list_dir_graph\adj_list_dir_graph.h"
//�������š���֪���·����㡱�롰δ֪���·����㡱֮���·��
#include "linked_list_head\linked_list_head.h"

typedef struct dijkstra_destination_path_s {
	//�յ�����
	int destination;
	//��㵽�յ����·����Ȩ��
	int weight;
	//���·���У������յ����һ���ڽӵ�����
	int last_adj_index;
} *dijkstra_destination_path;

typedef struct dijkstra_shortest_path_s {
	//�������
	int source_index;
	//���·����
	dijkstra_destination_path destination_path;
}*dijkstra_shortest_path;

//ͨ��������꣬������㵽ͼ���������Dijkstra���·����
dijkstra_shortest_path CreateDijkstraShorestPath(adj_list_dir_graph graph, int source);

//���Dijkstra���·����
void PrintDijkstraShorestPath(adj_list_dir_graph graph, dijkstra_shortest_path path);

//�������������㣬������·��
void GetDijkstraPath(adj_list_dir_graph graph, int out, int in);

//����Dijkstra���·����
void DestroyDijkstraShorestPath(dijkstra_shortest_path * path);

#endif