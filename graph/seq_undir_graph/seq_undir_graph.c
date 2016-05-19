#include "seq_undir_graph.h"
#include "..\others\cir_queue.h"

//遍历图的结点时的具体操作
void SeqUndirGraphTraverseAction(seq_undir_graph graph, int index);
//深度优先遍历图的递归操作
void SeqUndirGraphLoopD(seq_undir_graph graph, int index, bool * visited);

seq_undir_graph SeqUndirGraphInit(int num_vex)
{
	seq_undir_graph graph = (seq_undir_graph) malloc(sizeof(struct seq_undir_graph_node_s));
	if (!graph) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	//初始化结点
	graph->vex = (seq_undir_graph_vex) malloc(sizeof(struct seq_undir_graph_vex_s));
	if (!graph->vex) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	graph->vex->elem = (seq_undir_graph_vex_elemtype *) malloc(sizeof(seq_undir_graph_vex_elemtype) * num_vex);
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

void SeqUndirGraphClear(seq_undir_graph graph)
{
	//清空结点表
	graph->vex->len = 0;
	//清空权重表
	for (int i = 0; i < graph->vex->num_vex; i++)
		for (int j = 0; j < graph->vex->num_vex; j++)
			graph->weight[i][j] = 0;
}

void SeqUndirGraphDestroy(seq_undir_graph * pgraph)
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

void SeqUndirGraphPrint(seq_undir_graph graph)
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
}

bool SeqUndirGraphVexExist(seq_undir_graph graph, int index)
{
	if (index >= 0 && index < graph->vex->len)
		return true;
	return false;
}

bool SeqUndirGraphAddEdge(seq_undir_graph graph, int edge1, int edge2, int weight)
{
	if (SeqUndirGraphVexExist(graph, edge1) && SeqUndirGraphVexExist(graph, edge2)) {
		graph->weight[edge1][edge2] = weight;
		graph->weight[edge2][edge1] = weight;
		return true;
	}
	printf("Illegal input.\n");
	return false;
}

bool SeqUndirGraphDelEdge(seq_undir_graph graph, int edge1, int edge2)
{
	if (SeqUndirGraphVexExist(graph, edge1) && SeqUndirGraphVexExist(graph, edge2)) {
		graph->weight[edge1][edge2] = 0;
		graph->weight[edge2][edge1] = 0;
		return true;
	}
	printf("Illegal input.\n");
	return false;
}

bool SeqUndirGraphAddVex(seq_undir_graph graph, seq_undir_graph_vex_elemtype elem)
{
	if (graph->vex->len >= graph->vex->num_vex) {
		printf("The vertex list is full.\n");
		return false;
	}

	graph->vex->elem[graph->vex->len] = elem;
	graph->vex->len++;
	return true;
}

bool SeqUndirGraphDelVex(seq_undir_graph graph, int index)
{
	if (SeqUndirGraphVexExist(graph, index)) {
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


int SeqUndirGraphDegree(seq_undir_graph graph, int index)
{
	int n = graph->vex->num_vex;
	int degree;

	for (int i = 0; i < n; i++)
		if (graph->weight[i][index] > 0)
			degree++;

	return degree;
}

int SeqUndirGraphLocateVex(seq_undir_graph graph, seq_undir_graph_vex_elemtype elem)
{
	int n = graph->vex->num_vex;
	for (int i = 0; i < n; i++)
		if (elem == graph->vex->elem[i])
			return i;
	return -1;
}

seq_undir_graph_vex_elemtype SeqUndirGraphGetVex(seq_undir_graph graph, int index)
{
	if (SeqUndirGraphVexExist(graph, index))
		return graph->vex->elem[index];

	printf("Illegal input.\n");
	return 0;
}

int SeqUndirGraphFirstAdj(seq_undir_graph graph, int index)
{
	return SeqUndirGraphNextAdj(graph, index, -1);
}

int SeqUndirGraphNextAdj(seq_undir_graph graph, int index, int pre)
{
	if (SeqUndirGraphVexExist(graph, index)) {
		int n = graph->vex->len;
		for (int i = pre + 1; i < n; i++)
			if (graph->weight[index][i] != 0)
				return i;
		return -1;
	}
	printf("Illegal input.\n");
	return -2;
}

void SeqUndirGraphTraverseD(seq_undir_graph graph)
{
	int n = graph->vex->len;
	//创建bool型数组，存放结点是否已被访问
	bool * visited;
	visited = (bool *) malloc(sizeof(int) * n);
	if (!visited) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	for (int i = 0; i < n; i++)
		visited[i] = false;
	//遍历一遍图，防止图中有两个及以上的连通分量
	for (int index = 0; visited[index] == false; index++)
		SeqUndirGraphLoopD(graph, index, visited);

	free(visited);
}

void SeqUndirGraphTraverseB(seq_undir_graph graph)
{
	int n = graph->vex->len;
	//创建bool型数组，存放结点是否已被访问
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
		//遍历一遍图，防止图中有两个及以上的连通分量
		if (visited[i] == false) {
			//把元素入队
			CirQueueEnter(queue, i);
			visited[i] = true;

			do {
				//元素出队，并进行操作
				int index = CirQueueExit(queue);
				SeqUndirGraphTraverseAction(graph, index);
				//查找第一个“子节点”
				int adj_index = SeqUndirGraphFirstAdj(graph, index);
				//广度遍历
				while (adj_index >= 0) {
					if (visited[adj_index] == false) {
						//子节点入队
						CirQueueEnter(queue, adj_index);
						visited[adj_index] = true;
					}
					//查找同一“父节点”的下一个“子节点”
					adj_index = SeqUndirGraphNextAdj(graph, index, adj_index);
				}
			} while (!CirQueueEmpty(queue));
		}
	}

	free(visited);
	CirQueueDestroy(&queue);
}

void SeqUndirGraphLoopD(seq_undir_graph graph, int index, bool * visited)
{
	if (visited[index] == true)
		return;

	SeqUndirGraphTraverseAction(graph, index);
	visited[index] = true;

	int tmp_index = SeqUndirGraphFirstAdj(graph, index);
	while (tmp_index >= 0) {
		SeqUndirGraphLoopD(graph, tmp_index, visited);
		tmp_index = SeqUndirGraphNextAdj(graph, index, tmp_index);
	}
}

void SeqUndirGraphTraverseAction(seq_undir_graph graph, int index)
{
	printf("%c\n", graph->vex->elem[index]);
}