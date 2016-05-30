#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "adj_list_dir_graph\adj_list_dir_graph.h"
//用链表存放“已知最短路径结点”与“未知最短路径结点”之间的路径
#include "linked_list_head\linked_list_head.h"

typedef struct dijkstra_destination_path_s {
	//终点坐标
	int destination;
	//起点到终点最短路径的权重
	int weight;
	//最短路径中，到达终点的上一个邻接点坐标
	int last_adj_index;
} *dijkstra_destination_path;

typedef struct dijkstra_shortest_path_s {
	//起点坐标
	int source_index;
	//最短路径表
	dijkstra_destination_path destination_path;
}*dijkstra_shortest_path;

//通过起点坐标，创造起点到图中其他结点Dijkstra最短路径表
dijkstra_shortest_path CreateDijkstraShorestPath(adj_list_dir_graph graph, int source);

//输出Dijkstra最短路径表
void PrintDijkstraShorestPath(adj_list_dir_graph graph, dijkstra_shortest_path path);

//给定出结点和入结点，输出最短路径
void GetDijkstraPath(adj_list_dir_graph graph, int out, int in);

//销毁Dijkstra最短路径表
void DestroyDijkstraShorestPath(dijkstra_shortest_path * path);

#endif