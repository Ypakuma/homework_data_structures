#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "adj_list_undir_graph\adj_list_undir_graph.h"

//返回一个用邻接表存储的最小生成树，若没有最小生成树，返回NULL
adj_list_undir_graph CreateKruskal(adj_list_undir_graph graph);


#endif