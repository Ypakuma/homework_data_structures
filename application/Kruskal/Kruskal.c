#include "Kruskal.h"
#include "quick_sort\quick_sort.h"

//��Kruskal�㷨�������洢ͼ�Ľ��ı�
typedef struct kruskal_vex_s {
	int index_vex;
	//�����ý���Ƿ�ѡȡ����Ϊ0����û�У���Ϊ1�����ѱ�ѡȡ
	bool isselected;
} * kruskal_vex_list;

//��Kruskal�㷨�������洢ͼ�ıߵı�
typedef struct kruskal_edge_s {
	int index_vex_1;
	int index_vex_2;
	int weight;
} * kruskal_edge_list;

//����Kruskal������߱�
void DestroyKruskalVexEdgeList(kruskal_vex_list * vex_list, kruskal_edge_list * edge_list);

adj_list_undir_graph CreateKruskal(adj_list_undir_graph graph)
{
	kruskal_vex_list vex_list;
	kruskal_edge_list edge_list;
	adj_list_undir_graph span_tree;

	//��ʼ��Kruskal������߱�
	vex_list = (kruskal_vex_list) malloc(sizeof(struct kruskal_vex_s) * graph->len_vex);
	if (!vex_list) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	edge_list = (kruskal_edge_list) malloc(sizeof(struct kruskal_edge_s) * graph->len_edge);
	if (!edge_list) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	span_tree = AdjListUndirGraphInit(graph->len_vex);

	int n_vex = graph->len_vex;
	int n_edge = 0;

	//��Ҫ����С��������ͼ�Ľ����ߵ���Ϣ�浽����������
	for (int i = 0; i < n_vex; i++) {
		//�������Ϣ����
		vex_list[i].index_vex = i;
		vex_list[i].isselected = false;
		//������Ϣ����
		adj_list_undir_graph_adj_node * pedge;
		pedge = graph->vex[i].first_adj;
		while (pedge) {
			if (pedge->adj_index < i) {
				pedge = pedge->next_adj;
				continue;
			}

			edge_list[n_edge].index_vex_1 = i;
			edge_list[n_edge].index_vex_2 = pedge->adj_index;
			edge_list[n_edge].weight = pedge->weight;
			n_edge++;
			pedge = pedge->next_adj;
		}
	}

	//�Ա߽�㰴Ȩ����������
	quick_sort(edge_list, 0, graph->len_edge - 1);

	//��ѡ����С�������ı���
	int i = 0;
	while (i < n_vex - 1 && i < n_edge) {
		AdjListUndirGraphAddEdge(span_tree, edge_list[i].index_vex_1, edge_list[i].index_vex_2, edge_list[i].weight);
		vex_list[edge_list[i].index_vex_1].isselected = true;
		vex_list[edge_list[i].index_vex_2].isselected = true;
		i++;
	}

	//�Ա��������һ�α�����ͨ���Ƿ�ֻ��һ����ͨ�������ж���С�������Ƿ����ɳɹ�
	//���ѽ��Ԫ����Ϣ������С��������
	for (int i = 0; i < n_vex; i++) {
		if (vex_list[i].isselected == false) {
			free(vex_list);
			free(edge_list);
			AdjListUndirGraphDestroy(&span_tree);
			return NULL;
		}
		AdjListUndirGraphAddVex(span_tree, graph->vex[i].elem);
	}

	free(vex_list);
	free(edge_list);

	span_tree->len_edge = n_vex - 1;
	span_tree->len_vex = n_vex;

	return span_tree;
}

void DestroyKruskalVexEdgeList(kruskal_vex_list * vex_list, kruskal_edge_list * edge_list)
{
	free(*vex_list);
	free(*edge_list);
	(*vex_list) = NULL;
	(*edge_list) = NULL;
}