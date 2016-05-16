#include "seq_dir_graph.h"
#include "cir_queue.h"

//遍历图的结点时的具体操作
void SeqDirGraphTraverseAction(seq_dir_graph graph, int index);
//深度优先遍历图的递归操作
void SeqDirGraphLoopD(seq_dir_graph graph, int index, bool * visited);

seq_dir_graph SeqDirGraphInit(int num_vex)
{
	seq_dir_graph graph = (seq_dir_graph) malloc(sizeof(struct seq_dir_graph_node_s));
	if (!graph) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	//初始化结点
	graph->vex = (seq_dir_graph_vex) malloc(sizeof(struct seq_dir_graph_vex_s));
	if (!graph->vex) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	graph->vex->elem = (seq_dir_graph_vex_elemtype *) malloc(sizeof(seq_dir_graph_vex_elemtype) * num_vex);
	if (!(graph->vex->elem)) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	graph->vex->num_vex = num_vex;
	graph->vex->len = 0;

	//初始化权重矩阵；
	graph->weight = (int **) malloc(sizeof(int) * num_vex);
	if (!(graph->weight)) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	for (int i = 0; i < num_vex; i++) {
		graph->weight[i] = (int *) malloc(sizeof(int) * num_vex);
		if (!(graph->weight[i])) {
			printf("Fail to allocate memory.\n");
			exit(0);
		}
		for (int j = 0; j < num_vex; j++)
			graph->weight[i][j] = 0;
	}

	return graph;
}

void SeqDirGraphClear(seq_dir_graph graph)
{
	graph->vex->len = 0;
	for (int i = 0; i < graph->vex->num_vex; i++)
		for (int j = 0; j < graph->vex->num_vex; j++)
			graph->weight[i][j] = 0;
}

void SeqDirGraphDestroy(seq_dir_graph * pgraph)
{
	if (*pgraph) {
		int n = (*pgraph)->vex->num_vex;
		for (int i = 0; i < n; i++)
			free((*pgraph)->weight[i]);
		free((*pgraph)->weight);
		free((*pgraph)->vex->elem);
		free((*pgraph)->vex);
		free(*pgraph);
		(*pgraph) = NULL;
	}
}

void SeqDirGraphPrint(seq_dir_graph graph)
{
	int n = graph->vex->len;
	printf("元素:\n ");
	for (int i = 0; i < n; i++)
		printf("\t%c", graph->vex->elem[i]);

	printf("\n\n权重:\n ");
	for (int i = 0; i < n; i++)
		printf("\t%d", i);

	for (int i = 0; i < n; i++) {
		printf("\n%d", i);
		for (int j = 0; j < n; j++)
			printf("\t%d", graph->weight[i][j]);
	}

	printf("\n");
	return 0;
}

bool SeqDirGraphVexExist(seq_dir_graph graph, int index)
{
	if (index >= 0 && index < graph->vex->len)
		return true;
	return false;
}

bool SeqDirGraphAddEdge(seq_dir_graph graph, int out, int in, int weight)
{
	if (SeqDirGraphVexExist(graph, out) && SeqDirGraphVexExist(graph, in)) {
		graph->weight[out][in] = weight;
		return true;
	}
	printf("Illegal input.\n");
	return false;
}

bool SeqDirGraphDelEdge(seq_dir_graph graph, int out, int in)
{
	if (SeqDirGraphVexExist(graph, out) && SeqDirGraphVexExist(graph, in)) {
		graph->weight[out][in] = 0;
		return true;
	}
	printf("Illegal input.\n");
	return false;
}

bool SeqDirGraphAddVex(seq_dir_graph graph, seq_dir_graph_vex_elemtype elem)
{
	if (graph->vex->len >= graph->vex->num_vex) {
		printf("The vertex list is full.\n");
		return false;
	}

	graph->vex->elem[graph->vex->len] = elem;
	graph->vex->len++;
	return true;
}

bool SeqDirGraphDelVex(seq_dir_graph graph, int index)
{
	if (SeqDirGraphVexExist(graph, index)) {
		graph->vex->len--;
		int tmp_index = index;
		int * ptmp = graph->weight[tmp_index];
		while (tmp_index < graph->vex->len) {
			//把邻接矩阵每一行向上移一行
			graph->weight[tmp_index] = graph->weight[tmp_index + 1];
			//把结点元素表每一项向前移一项
			graph->vex->elem[tmp_index] = graph->vex->elem[tmp_index + 1];
			tmp_index++;
		}
		graph->weight[tmp_index] = ptmp;
		
		int n = graph->vex->num_vex;
		for (int i = 0; i < n; i++) {
			//对最后一行清零
			graph->weight[tmp_index][i] = 0;
			//把邻接矩阵每一列向前移一列
			for (int j = index; j < n; j++)
				graph->weight[i][j] = graph->weight[i][j + 1];
			//对最后一列清零

			graph->weight[i][n - 1] = 0;
		}
		return true;
	}

	printf("Illegal input.\n");
	return false;
}

int SeqDirGraphLocateVex(seq_dir_graph graph, seq_dir_graph_vex_elemtype elem)
{
	int n = graph->vex->num_vex;
	for (int i = 0; i < n; i++)
		if (elem == graph->vex->elem[i])
			return i;
	return -1;
}

seq_dir_graph_vex_elemtype SeqDirGraphGetVex(seq_dir_graph graph, int index)
{
	if (SeqDirGraphVexExist(graph, index))
		return graph->vex->elem[index];

	printf("Illegal input.\n");
	return 0;
}

int SeqDirGraphFirstAdj(seq_dir_graph graph, int index)
{
	SeqDirGraphNextAdj(graph, index, -1);
}

int SeqDirGraphNextAdj(seq_dir_graph graph, int index, int pre)
{
	if (SeqDirGraphVexExist(graph, index)) {
		int n = graph->vex->len;
		for (int i = pre + 1; i < n; i++)
			if (graph->weight[index][i] != 0)
				return i;
		return -1;
	}
	printf("Illegal input.\n");
	return -2;
}

void SeqDirGraphTraverseD(seq_dir_graph graph)
{
	int n = graph->vex->len;

	bool * visited;
	visited = (bool *) malloc(sizeof(int) * n);
	if (!visited) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	for (int i = 0; i < n; i++)
		visited[i] = false;

	for (int index = 0; visited[index] == false; index++)
		SeqDirGraphLoopD(graph, index, visited);

	free(visited);
}

void SeqDirGraphLoopD(seq_dir_graph graph, int index, bool * visited)
{
	if (visited[index] == true)
		return;

	SeqDirGraphTraverseAction(graph, index);
	visited[index] = true;

	int next_index = SeqDirGraphFirstAdj(graph, index);
	while (next_index >= 0) {
		SeqDirGraphLoopD(graph, next_index, visited);
		next_index = SeqDirGraphNextAdj(graph, index, next_index);
	}
}

void SeqDirGraphTraverseB(seq_dir_graph graph)
{
	int n = graph->vex->len;

	bool * visited;
	visited = (bool *) malloc(sizeof(int) * n);
	if (!visited) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	for (int i = 0; i < n; i++)
		visited[i] = false;

	cir_queue queue;
	queue = CirQueueInit(graph->vex->num_vex);

	for (int i = 0; visited[i] == false; i++) {
		if (visited[i] == false) {
			CirQueueEnter(queue, i);
			visited[i] = true;

			do {
				int index = CirQueueExit(queue);
				SeqDirGraphTraverseAction(graph, index);
				int adj_index = SeqDirGraphFirstAdj(graph, index);

				while (adj_index >= 0) {
					if (visited[adj_index] == false) {
						CirQueueEnter(queue, adj_index);
						visited[adj_index] = true;
					}
					adj_index = SeqDirGraphNextAdj(graph, index, adj_index);
				}
			} while (!CirQueueEmpty(queue));
		}
	}

	free(visited);
	CirQueueDestroy(&queue);
}

void SeqDirGraphTraverseAction(seq_dir_graph graph, int index)
{
	printf("%c\n", graph->vex->elem[index]);
}
