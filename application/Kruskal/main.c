#include "Kruskal.h"
#include "adj_list_undir_graph\adj_list_undir_graph.h"

int main(void)
{
	adj_list_undir_graph graph;

	graph = AdjListUndirGraphInit(10);
	AdjListUndirGraphAddVex(graph, 'a');
	AdjListUndirGraphAddVex(graph, 'b');
	AdjListUndirGraphAddVex(graph, 'c');
	AdjListUndirGraphAddVex(graph, 'd');
	AdjListUndirGraphAddVex(graph, 'e');
	AdjListUndirGraphAddVex(graph, 'f');

	AdjListUndirGraphAddEdge(graph, 0, 1, 6);
	AdjListUndirGraphAddEdge(graph, 0, 2, 1);
	AdjListUndirGraphAddEdge(graph, 0, 3, 5);
	AdjListUndirGraphAddEdge(graph, 1, 2, 5);
	AdjListUndirGraphAddEdge(graph, 2, 3, 5);
	AdjListUndirGraphAddEdge(graph, 1, 4, 5);
	AdjListUndirGraphAddEdge(graph, 4, 2, 6);
	AdjListUndirGraphAddEdge(graph, 4, 5, 6);
	AdjListUndirGraphAddEdge(graph, 2, 5, 4);
	AdjListUndirGraphAddEdge(graph, 3, 5, 2);

	AdjListUndirGraphPrint(graph);

	adj_list_undir_graph kruskal;
	kruskal = CreateKruskal(graph);

	AdjListUndirGraphPrint(kruskal);

	AdjListUndirGraphDestroy(&graph);
	AdjListUndirGraphDestroy(&kruskal);

	return 0;
}