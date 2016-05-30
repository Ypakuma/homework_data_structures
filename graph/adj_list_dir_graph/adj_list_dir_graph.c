#include "adj_list_dir_graph.h"

//遍历图的结点时的具体操作
void AdjListDirGraphTraverseAction(adj_list_dir_graph graph, int index);
//深度优先遍历图的递归操作
void AdjListDirGraphLoopD(adj_list_dir_graph graph, int index, bool * visited);
//广度优先遍历图的递归操作
void AdjListDirGraphLoopB(adj_list_dir_graph graph, int index, bool * visited);

adj_list_dir_graph AdjListDirGraphInit(int num_vex)
{
	adj_list_dir_graph graph;
	graph = (adj_list_dir_graph) malloc(sizeof(struct adj_list_dir_graph_node_s));
	if (!graph) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	graph->len = 0;
	graph->num_vex = num_vex;
	graph->vex = (adj_list_dir_graph_vex_node *) malloc(sizeof(adj_list_dir_graph_vex_node) * num_vex);
	if (!graph->vex) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	for (int i = 0; i < num_vex; i++)
		graph->vex[i].first_adj = NULL;

	return graph;
}

void AdjListDirGraphClear(adj_list_dir_graph graph)
{
	int n = graph->len;
	//删除每个入结点后的边
	for (int i = 0; i < n; i++) {
		adj_list_dir_graph_adj_node * pnode;
		pnode = graph->vex[i].first_adj;
		while (pnode != NULL) {
			adj_list_dir_graph_adj_node * tmp_pnode;
			//tmp_pnode指向将free的下一个结点
			tmp_pnode = pnode->next_adj;
			free(pnode);
			pnode = tmp_pnode;
		}
	}
	//清空结点
	graph->len = 0;
}

void AdjListDirGraphDestroy(adj_list_dir_graph * graph)
{
	AdjListDirGraphClear(*graph);
	free((*graph)->vex);
	free(*graph);
	(*graph) = NULL;
}

void AdjListDirGraphPrint(adj_list_dir_graph graph)
{
	int n = graph->len;
	for (int i = 0; i < n; i++) {
		printf("%d  %c\t", i, graph->vex[i].elem);
		adj_list_dir_graph_adj_node * pnode;
		pnode = graph->vex[i].first_adj;
		while (pnode != NULL) {
			printf("%d\t", pnode->adj_index);
			pnode = pnode->next_adj;
		}
		printf("\n");
	}
	printf("\n");
}

bool AdjListDirGraphVexExist(adj_list_dir_graph graph, int index)
{
	if (index >= 0 && index < graph->num_vex)
		return true;
	return false;
}


bool AdjListDirGraphAddEdge(adj_list_dir_graph graph, int out, int in, int weight)
{
	if (AdjListDirGraphVexExist(graph, out) && AdjListDirGraphVexExist(graph, in)) {
		//创建新边（新的邻接结点）
		adj_list_dir_graph_adj_node * pnode;
		pnode = (adj_list_dir_graph_adj_node *) malloc(sizeof(adj_list_dir_graph_adj_node));
		if (!pnode) {
			printf("Fail to allocate memory.\n");
			exit(0);
		}
		pnode->adj_index = in;
		pnode->weight = weight;

		//将新的邻接结点插入邻接表
		adj_list_dir_graph_adj_node * locat = graph->vex[out].first_adj;
		//出结点出度为0，新的边权重最小
		if (locat == NULL || locat->weight > weight) {
			pnode->next_adj = locat;
			graph->vex[out].first_adj = pnode;
			return true;
		}
		//locat指向插入的位置
		while (locat->next_adj != NULL && locat->next_adj->adj_index > in)
			locat = locat->next_adj;

		pnode->next_adj = locat->next_adj;
		locat->next_adj = pnode;

		return true;
	}

	printf("Illegal input.\n");
	return false;
}

bool AdjListDirGraphDelEdge(adj_list_dir_graph graph, int out, int in)
{
	if (AdjListDirGraphVexExist(graph, out) && AdjListDirGraphVexExist(graph, in)) {
		adj_list_dir_graph_adj_node * pnode = graph->vex[out].first_adj;
		//如果第一个边就是要删除的边
		if (pnode->adj_index == in) {
			graph->vex[out].first_adj = pnode->next_adj;
			free(pnode);
		}

		else {
			//找到要删除的边的前一条边，并删除
			while (pnode->next_adj != NULL && pnode->next_adj->adj_index == in)
				pnode = pnode->next_adj;
			//没找到要删除的边，返回false
			if (pnode->next_adj == NULL)
				return false;
			adj_list_dir_graph_adj_node * tmp_pnode = pnode->next_adj;
			//tmp_pnode指向要删除的结点
			pnode->next_adj = tmp_pnode->next_adj;
			free(tmp_pnode);
		}
		return true;
	}

	printf("Illegal input.\n");
	return false;
}

bool AdjListDirGraphAddVex(adj_list_dir_graph graph, adj_list_dir_graph_vex_elemtype elem)
{
	if (graph->len >= graph->num_vex) {
		printf("The graph is full.\n");
		return false;
	}

	graph->vex[graph->len].elem = elem;
	graph->len++;
	return true;
}

bool AdjListDirGraphDelVex(adj_list_dir_graph graph, int index)
{
	if (AdjListDirGraphVexExist(graph, index)) {
		graph->len--;
		//删除待删除结点后的边
		adj_list_dir_graph_adj_node * pnode;
		pnode = graph->vex[index].first_adj;
		while (pnode != NULL) {
			adj_list_dir_graph_adj_node * tmp_pnode;
			//tmp_pnode指向将free的下一个结点
			tmp_pnode = pnode->next_adj;
			free(pnode);
			pnode = tmp_pnode;
		}

		int tmp_index = index;
		//tmp_index从待删除结点开始，一直递增，使结点表每一项前移
		while (tmp_index < graph->len) {
			//把结点表中每一项前移
			graph->vex[tmp_index].elem = graph->vex[tmp_index + 1].elem;
			graph->vex[tmp_index].first_adj = graph->vex[tmp_index + 1].first_adj;
			tmp_index++;
		}
		graph->vex[graph->len].first_adj = NULL;

		//删除其他以待删除结点为入结点的边
		int n = graph->len;
		for (int i = 0; i < n; i++) {
			adj_list_dir_graph_adj_node * pnode;
			pnode = graph->vex[i].first_adj;
			while (pnode != NULL) {
				if (pnode->adj_index == index) {
					pnode = pnode->next_adj;
					AdjListDirGraphDelEdge(graph, i, index);
					continue;
				}
				if (pnode->adj_index > index)
					pnode->adj_index--;
				pnode = pnode->next_adj;
			}
		}

		return true;
	}

	printf("Illegal input.\n");
	return false;
}

int AdjListDirGraphIndegree(adj_list_dir_graph graph, int index)
{
	int outdegree = 0;
	int n = graph->len;
	adj_list_dir_graph_adj_node * pnode;

	for (int i = 0; i < n; i++) {
		pnode = graph->vex[i].first_adj;
		while (pnode != NULL && pnode->adj_index <= index) {
			if (pnode->adj_index == index) {
				outdegree++;
				break;
			}
			pnode = pnode->next_adj;
		}
	}

	return outdegree;
}

int AdjListDirGraphOutdegree(adj_list_dir_graph graph, int index)
{
	int indegree = 0;
	adj_list_dir_graph_adj_node * pnode;

	pnode = graph->vex[index].first_adj;
	while (pnode != NULL) {
		indegree++;
		pnode = pnode->next_adj;
	}

	return indegree;
}

int AdjListDirGraphLocateVex(adj_list_dir_graph graph, adj_list_dir_graph_vex_elemtype elem)
{
	int n = graph->len;

	for (int i = 0; i < n; i++) {
		if (graph->vex[i].elem == elem)
			return i;
	}

	return -1;
}

adj_list_dir_graph_vex_elemtype AdjListDirGraphGetVex(adj_list_dir_graph graph, int index)
{
	if (AdjListDirGraphVexExist(graph, index))
		return graph->vex[index].elem;

	printf("Illegal input.\n");
	return 0;
}

int AdjListDirGraphFirstAdj(adj_list_dir_graph graph, int index)
{
	return graph->vex[index].first_adj->adj_index;
}

int AdjListDirGraphNextAdj(adj_list_dir_graph graph, int index, int pre)
{
	if (AdjListDirGraphVexExist(graph, index)) {
		adj_list_dir_graph_adj_node * pnode;
		pnode = graph->vex[index].first_adj;

		while (pnode != NULL && pnode->adj_index <= pre)
			pnode = pnode->next_adj;

		if (pnode == NULL)
			return - 1;
		return pnode->adj_index;
	}

	printf("Illegal input.\n");
	return -2;
}

void AdjListDirGraphTraverseD(adj_list_dir_graph graph)
{
	int n = graph->len;
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
	for (int index = 0; index < n; index++)
		if (visited[index] == false)
			AdjListDirGraphLoopD(graph, index, visited);

	free(visited);
}

void AdjListDirGraphLoopD(adj_list_dir_graph graph, int index, bool * visited)
{
	if (visited[index] == false) {
		AdjListDirGraphTraverseAction(graph, index);
		visited[index] = true;

		int next_index = AdjListDirGraphFirstAdj(graph, index);
		while (next_index >= 0) {
			//递归，深度遍历
			AdjListDirGraphLoopD(graph, next_index, visited);
			next_index = AdjListDirGraphNextAdj(graph, index, next_index);
		}
	}
}

void AdjListDirGraphTraverseB(adj_list_dir_graph graph)
{
	int n = graph->len;
	//创建bool型数组，存放结点是否已被访问
	bool * visited;
	visited = (bool *) malloc(sizeof(int) * n);
	if (!visited) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	for (int i = 0; i < n; i++)
		visited[i] = false;

	for (int i = 0; i < n; i++)
		if (visited[i] == false)
			AdjListDirGraphLoopB(graph, i, visited);

	free(visited);
}

void AdjListDirGraphLoopB(adj_list_dir_graph graph, int index, bool * visited)
{
	if (visited[index] == false) {
		AdjListDirGraphTraverseAction(graph, index);
		visited[index] = true;

		adj_list_dir_graph_adj_node * pnode;

		//访问结点的每个子结点
		pnode = graph->vex[index].first_adj;
		while (pnode != NULL) {
			if (visited[pnode->adj_index] == false) {
				AdjListDirGraphTraverseAction(graph, pnode->adj_index);
				visited[pnode->adj_index] = true;
			}
			pnode = pnode->next_adj;
		}

		//对每个子结点递归调用
		pnode = graph->vex[index].first_adj;
		while (pnode != NULL) {
			AdjListDirGraphLoopB(graph, pnode->adj_index, visited);
			pnode = pnode->next_adj;
		}
	}
}


void AdjListDirGraphTraverseAction(adj_list_dir_graph graph, int index)
{
	printf("%c\n", graph->vex[index].elem);
}

