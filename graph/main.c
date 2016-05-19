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

	//int ans = AdjListDirGraphIndegree(graph, 2);
	//ans = AdjListDirGraphOutdegree(graph, 4);

	//ans = AdjListDirGraphLocateVex(graph, 'b');
	//ans = AdjListDirGraphLocateVex(graph, 'g');

	//ans = AdjListDirGraphFirstAdj(graph, 2);
	//ans = AdjListDirGraphNextAdj(graph, 3, 3);

	//AdjListDirGraphDelEdge(graph, 0, 1);
	//AdjListDirGraphPrint(graph);
	//AdjListDirGraphDelVex(graph, 3);
	//AdjListDirGraphPrint(graph);

	AdjListDirGraphTraverseB(graph);


	AdjListDirGraphClear(graph);
	AdjListDirGraphDestroy(&graph);

	return 0;
}