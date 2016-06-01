#include "Kruskal.h"
#include "quick_sort\quick_sort.h"

//��Kruskal�㷨�������洢ͼ�ıߵı�
typedef struct kruskal_edge_s {
	int index_vex_1;
	int index_vex_2;
	int weight;
} * kruskal_edge_list;

//��ͨ������
//��ʼ��ʱ��ÿ������Ӧһ����ͨ����
//ÿ����һ����С���������������һ����ͨ�����Ľ���Ƶ���һ����ͨ��������
//ͬʱ�����߽�����ͨ�����±��Ϊ�ƺ����ͨ�����±�
typedef struct kruskal_flag_s {
	//����±�
	int index_vex;
	//��ͨ�����±�
	int index_flag;
	struct kruskal_flag_s * next_node;
} kruskal_flag_node, *kruskal_flag;


adj_list_undir_graph CreateKruskal(adj_list_undir_graph graph)
{
	kruskal_edge_list edge_list;
	kruskal_flag flag;
	adj_list_undir_graph span_tree;

	//��ʼ��Kruskal�߱�����ͨ������
	edge_list = (kruskal_edge_list) malloc(sizeof(struct kruskal_edge_s) * graph->len_edge);
	if (!edge_list) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	flag = (kruskal_flag) malloc(sizeof(struct kruskal_flag_s) * graph->len_vex);
	if (!flag) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	span_tree = AdjListUndirGraphInit(graph->len_vex);

	int n_vex = graph->len_vex;
	int n_edge = 0;

	//��Ҫ����С��������ͼ�Ľ����ߵ���Ϣ�浽����������
	for (int i = 0; i < n_vex; i++) {
		//����ͨ������Ϣ����
		flag[i].index_flag = i;
		flag[i].next_node = malloc(sizeof(struct kruskal_flag_s));
		if (!flag[i].next_node) {
			printf("Fail to allocate memory.\n");
			exit(0);
		}
		flag[i].next_node->index_vex = i;
		flag[i].next_node->index_flag = i;
		flag[i].next_node->next_node = NULL;

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

		//����������С������
		AdjListUndirGraphAddVex(span_tree, graph->vex[i].elem);
	}

	//�Ա߽�㰴Ȩ����������
	quick_sort(edge_list, 0, graph->len_edge - 1);

	//��ѡ����С�������ı���
	int n = 0;
	//��ǰȨ����С���±�
	int index = 0;
	while (n < n_vex - 1 && index < n_edge) {
		//������������ͬһ����ͨ����������
		if (flag[edge_list[index].index_vex_1].index_flag == flag[edge_list[index].index_vex_2].index_flag) {
			index++;
			continue;
		}

		AdjListUndirGraphAddEdge(span_tree, edge_list[index].index_vex_1, edge_list[index].index_vex_2, edge_list[index].weight);

		//pnodeָ����ͨ��������index_vex_1�����һ����㣬��������ͨ��������index_vex_2�����н��
		kruskal_flag_node * pnode = flag[flag[edge_list[index].index_vex_1].index_flag].next_node;
		while (pnode->next_node)
			pnode = pnode->next_node;
		pnode->next_node = flag[flag[edge_list[index].index_vex_2].index_flag].next_node;

		flag[flag[edge_list[index].index_vex_2].index_flag].next_node = NULL;

		//����index_vex_2Ϊ�±���������ڽ���flagֵ��ȫ����Ϊ��index_vex_1Ϊ�±�flagֵ
		pnode = pnode->next_node;
		while (pnode) {
			pnode->index_flag = edge_list[index].index_vex_1;
			flag[pnode->index_vex].index_flag = edge_list[index].index_vex_1;
			pnode = pnode->next_node;
		}

		index++;
		n++;
	}

	//�Ա��������һ�α�����ͨ���Ƿ�ֻ��һ����ͨ�������ж���С�������Ƿ����ɳɹ�
	//���ѽ��Ԫ����Ϣ������С��������
	for (int i = 0; i < n_vex - 1; i++) {
		if (flag[i].index_flag != flag[i + 1].index_flag) {
			free(edge_list);
			//����flag��
			for (int i = 0; i < n_vex; i++) {
				if (flag[i].next_node != NULL) {
					kruskal_flag_node * pnode = flag[i].next_node;
					kruskal_flag_node * next_pnode = pnode->next_node;
					while (next_pnode) {
						free(pnode);
						pnode = next_pnode;
						next_pnode = pnode->next_node;
					}
					free(pnode);
				}
			}
			free(flag);
			AdjListUndirGraphDestroy(&span_tree);
			return NULL;
		}
	}

	free(edge_list);
	//����flag��
	for (int i = 0; i < n_vex; i++) {
		if (flag[i].next_node != NULL) {
			kruskal_flag_node * pnode = flag[i].next_node;
			kruskal_flag_node * next_pnode = pnode->next_node;
			while (next_pnode) {
				free(pnode);
				pnode = next_pnode;
				next_pnode = pnode->next_node;
			}
			free(pnode);
		}
	}
	free(flag);


	span_tree->len_edge = n_vex - 1;
	span_tree->len_vex = n_vex;

	return span_tree;
}
