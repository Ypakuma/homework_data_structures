#include "Kruskal.h"
#include "adj_list_undir_graph\adj_list_undir_graph.h"

int main(void)
{
	adj_list_undir_graph graph;

	graph = AdjListUndirGraphInit(10);
	AdjListUndirGraphAddVex(graph, 'a');
	AdjListUndirGraphAddVex(graph, 'b');
	AdjListUndirGraphAddVex(graph, 'd');
	AdjListUndirGraphAddVex(graph, 'e');
	AdjListUndirGraphAddVex(graph, 'f');
	AdjListUndirGraphAddVex(graph, 'g');
	AdjListUndirGraphAddVex(graph, 'c');


	AdjListUndirGraphAddEdge(graph, 0, 1, 2);
	AdjListUndirGraphAddEdge(graph, 1, 2, 10);
	AdjListUndirGraphAddEdge(graph, 2, 3, 6);
	AdjListUndirGraphAddEdge(graph, 3, 4, 1);
	AdjListUndirGraphAddEdge(graph, 4, 5, 5);
	AdjListUndirGraphAddEdge(graph, 5, 0, 4);
	AdjListUndirGraphAddEdge(graph, 6, 0, 1);
	AdjListUndirGraphAddEdge(graph, 6, 1, 3);
	AdjListUndirGraphAddEdge(graph, 6, 2, 7);
	AdjListUndirGraphAddEdge(graph, 6, 3, 4);
	AdjListUndirGraphAddEdge(graph, 6, 4, 8);
	AdjListUndirGraphAddEdge(graph, 6, 5, 2);

	AdjListUndirGraphPrint(graph);

	adj_list_undir_graph kruskal;
	kruskal = CreateKruskal(graph);

	AdjListUndirGraphPrint(kruskal);

	AdjListUndirGraphDestroy(&graph);
	AdjListUndirGraphDestroy(&kruskal);

	return 0;
}