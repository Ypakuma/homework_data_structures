#include "adj_list_undir_graph.h"


adj_list_undir_graph AdjListUndirGraphInit(int num_vex)
{
	adj_list_undir_graph graph;
	graph = (adj_list_undir_graph) malloc(sizeof(struct adj_list_undir_graph_node_s));
	if (!graph) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	graph->len_vex = 0;
	graph->len_edge = 0;
	graph->num_vex = num_vex;
	graph->vex = (adj_list_undir_graph_vex_node *) malloc(sizeof(adj_list_undir_graph_vex_node) * num_vex);
	if (!graph->vex) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	for (int i = 0; i < num_vex; i++)
		graph->vex[i].first_adj = NULL;

	return graph;
}

void AdjListUndirGraphClear(adj_list_undir_graph graph)
{
	int n = graph->len_vex;
	//ɾ��ÿ�������ı�
	for (int i = 0; i < n; i++) {
		adj_list_undir_graph_adj_node * pnode;
		pnode = graph->vex[i].first_adj;
		while (pnode != NULL) {
			adj_list_undir_graph_adj_node * tmp_pnode;
			//tmp_pnodeָ��free����һ�����
			tmp_pnode = pnode->next_adj;
			free(pnode);
			pnode = tmp_pnode;
		}
	}
	//��ս��
	graph->len_vex = 0;
	graph->len_edge = 0;
}

void AdjListUndirGraphDestroy(adj_list_undir_graph * graph)
{
	AdjListUndirGraphClear(*graph);
	free((*graph)->vex);
	free(*graph);
}

void AdjListUndirGraphPrint(adj_list_undir_graph graph)
{
	int n = graph->len_vex;
	for (int i = 0; i < n; i++) {
		printf("%d  %c\t", i, graph->vex[i].elem);
		adj_list_undir_graph_adj_node * pnode;
		pnode = graph->vex[i].first_adj;
		while (pnode != NULL) {
			printf("%d\t", pnode->adj_index);
			pnode = pnode->next_adj;
		}
		printf("\n");
	}

	printf("\n");
}

bool AdjListUndirGraphVexExist(adj_list_undir_graph graph, int index)
{
	if (index >= 0 && index < graph->num_vex)
		return true;
	return false;
}

bool AdjListUndirGraphAddEdge(adj_list_undir_graph graph, int vex1, int vex2, int weight)
{
	if (AdjListUndirGraphVexExist(graph, vex1) && AdjListUndirGraphVexExist(graph, vex2)) {
		//�����±ߣ��µ��ڽӽ�㣩
		adj_list_undir_graph_adj_node * pnode;
		pnode = (adj_list_undir_graph_adj_node *) malloc(sizeof(adj_list_undir_graph_adj_node));
		if (!pnode) {
			printf("Fail to allocate memory.\n");
			exit(0);
		}
		pnode->adj_index = vex2;

		//���µ��ڽӽ������ڽӱ�
		pnode->next_adj = graph->vex[vex1].first_adj;
		pnode->weight = weight;
		graph->vex[vex1].first_adj = pnode;

		//�ظ���������������±�
		pnode = (adj_list_undir_graph_adj_node *) malloc(sizeof(adj_list_undir_graph_adj_node));
		if (!pnode) {
			printf("Fail to allocate memory.\n");
			exit(0);
		}
		pnode->adj_index = vex1;

		//���µ��ڽӽ������ڽӱ�
		pnode->next_adj = graph->vex[vex2].first_adj;
		pnode->weight = weight;
		graph->vex[vex2].first_adj = pnode;

		graph->len_edge++;
		return true;
	}

	printf("Illegal input.\n");
	return false;
}

bool AdjListUndirGraphAddVex(adj_list_undir_graph graph, adj_list_undir_graph_vex_elemtype elem)
{
	if (graph->len_vex >= graph->num_vex) {
		printf("The graph is full.\n");
		return false;
	}

	graph->vex[graph->len_vex].elem = elem;
	graph->len_vex++;
	return true;
}

