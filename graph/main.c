#include "seq_dir_graph\seq_dir_graph.h"

int main(void)
{
	seq_dir_graph graph;

	graph = SeqDirGraphInit(10);
	SeqDirGraphAddVex(graph, 'a');
	SeqDirGraphAddVex(graph, 'b');
	SeqDirGraphAddVex(graph, 'c');
	SeqDirGraphAddVex(graph, 'd');
	SeqDirGraphAddVex(graph, 'e');
	SeqDirGraphAddVex(graph, 'f');

	SeqDirGraphAddEdge(graph, 0, 1, 5);
	SeqDirGraphAddEdge(graph, 0, 3, 7);
	SeqDirGraphAddEdge(graph, 1, 2, 4);
	SeqDirGraphAddEdge(graph, 2, 0, 8);
	SeqDirGraphAddEdge(graph, 2, 5, 9);
	SeqDirGraphAddEdge(graph, 3, 2, 5);
	SeqDirGraphAddEdge(graph, 3, 5, 6);
	SeqDirGraphAddEdge(graph, 4, 3, 5);
	SeqDirGraphAddEdge(graph, 5, 0, 3);
	SeqDirGraphAddEdge(graph, 5, 4, 1);

	SeqDirGraphPrint(graph);

	int ans = SeqDirGraphLocateVex(graph, 'b');
	ans = SeqDirGraphLocateVex(graph, 'g');

	//SeqDirGraphDelEdge(graph, 1, 2);
	//SeqDirGraphDelVex(graph, 2);

	SeqDirGraphTraverseB(graph);


	SeqDirGraphClear(graph);
	SeqDirGraphDestroy(&graph);

	return 0;
}