#include "Dijkstra.h"
#include "adj_list_dir_graph\adj_list_dir_graph.h"

int main(void)
{
	adj_list_dir_graph graph;

	graph = AdjListDirGraphInit(10);
	AdjListDirGraphAddVex(graph, 'a');
	AdjListDirGraphAddVex(graph, 'b');
	AdjListDirGraphAddVex(graph, 'c');
	AdjListDirGraphAddVex(graph, 'd');
	AdjListDirGraphAddVex(graph, 'e');
	AdjListDirGraphAddVex(graph, 'f');

	//AdjListDirGraphAddEdge(graph, 0, 1, 50);
	//AdjListDirGraphAddEdge(graph, 0, 2, 10);
	//AdjListDirGraphAddEdge(graph, 2, 0, 20);
	//AdjListDirGraphAddEdge(graph, 0, 4, 45);
	//AdjListDirGraphAddEdge(graph, 1, 4, 10);
	//AdjListDirGraphAddEdge(graph, 1, 2, 15);
	//AdjListDirGraphAddEdge(graph, 2, 3, 15);
	//AdjListDirGraphAddEdge(graph, 3, 1, 20);
	//AdjListDirGraphAddEdge(graph, 3, 4, 20);
	//AdjListDirGraphAddEdge(graph, 4, 3, 30);
	//AdjListDirGraphAddEdge(graph, 3, 5, 3);

	AdjListDirGraphAddEdge(graph, 0, 1, 5);
	AdjListDirGraphAddEdge(graph, 0, 3, 7);
	AdjListDirGraphAddEdge(graph, 1, 2, 4);
	AdjListDirGraphAddEdge(graph, 2, 0, 8);
	AdjListDirGraphAddEdge(graph, 2, 5, 9);
	AdjListDirGraphAddEdge(graph, 3, 2, 5);
	AdjListDirGraphAddEdge(graph, 3, 5, 6);
	AdjListDirGraphAddEdge(graph, 4, 3, 5);
	AdjListDirGraphAddEdge(graph, 5, 0, 3);
	AdjListDirGraphAddEdge(graph, 5, 4, 1);

	AdjListDirGraphPrint(graph);

	dijkstra_shortest_path shortest_path;
	shortest_path = CreateDijkstraShorestPath(graph, 0);
	PrintDijkstraShorestPath(graph, shortest_path);

	GetDijkstraPath(graph, 1, 5);

	DestroyDijkstraShorestPath(&shortest_path);
	AdjListDirGraphDestroy(&graph);


	return 0;
}