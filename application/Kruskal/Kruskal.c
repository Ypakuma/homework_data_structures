#include "Kruskal.h"
#include "quick_sort\quick_sort.h"

//在Kruskal算法内用来存储图的边的表
typedef struct kruskal_edge_s {
	int index_vex_1;
	int index_vex_2;
	int weight;
} * kruskal_edge_list;

//连通分量表
//初始化时，每个结点对应一个连通分量
//每加入一次最小生成树，则把其中一个连通分量的结点移到另一个连通分量后面
//同时，移走结点后，连通分量下标改为移后的连通分量下标
typedef struct kruskal_flag_s {
	//结点下标
	int index_vex;
	//连通分量下标
	int index_flag;
	struct kruskal_flag_s * next_node;
} kruskal_flag_node, *kruskal_flag;


adj_list_undir_graph CreateKruskal(adj_list_undir_graph graph)
{
	kruskal_edge_list edge_list;
	kruskal_flag flag;
	adj_list_undir_graph span_tree;

	//初始化Kruskal边表与连通分量表
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

	//把要求最小生成树的图的结点与边的信息存到两个数组中
	for (int i = 0; i < n_vex; i++) {
		//将连通分量信息存入
		flag[i].index_flag = i;
		flag[i].next_node = malloc(sizeof(struct kruskal_flag_s));
		if (!flag[i].next_node) {
			printf("Fail to allocate memory.\n");
			exit(0);
		}
		flag[i].next_node->index_vex = i;
		flag[i].next_node->index_flag = i;
		flag[i].next_node->next_node = NULL;

		//将边信息存入
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

		//将结点加入最小生成树
		AdjListUndirGraphAddVex(span_tree, graph->vex[i].elem);
	}

	//对边结点按权重升序排序
	quick_sort(edge_list, 0, graph->len_edge - 1);

	//被选入最小生成树的边数
	int n = 0;
	//当前权重最小边下标
	int index = 0;
	while (n < n_vex - 1 && index < n_edge) {
		//如果两结点属于同一个连通分量则跳过
		if (flag[edge_list[index].index_vex_1].index_flag == flag[edge_list[index].index_vex_2].index_flag) {
			index++;
			continue;
		}

		AdjListUndirGraphAddEdge(span_tree, edge_list[index].index_vex_1, edge_list[index].index_vex_2, edge_list[index].weight);

		//pnode指向连通分量表中index_vex_1的最后一个结点，再连上连通分量表中index_vex_2的所有结点
		kruskal_flag_node * pnode = flag[flag[edge_list[index].index_vex_1].index_flag].next_node;
		while (pnode->next_node)
			pnode = pnode->next_node;
		pnode->next_node = flag[flag[edge_list[index].index_vex_2].index_flag].next_node;

		flag[flag[edge_list[index].index_vex_2].index_flag].next_node = NULL;

		//把以index_vex_2为下标的所有相邻结点的flag值，全部改为以index_vex_1为下标flag值
		pnode = pnode->next_node;
		while (pnode) {
			pnode->index_flag = edge_list[index].index_vex_1;
			flag[pnode->index_vex].index_flag = edge_list[index].index_vex_1;
			pnode = pnode->next_node;
		}

		index++;
		n++;
	}

	//对边数组进行一次遍历，通过是否只有一个连通分量，判断最小生成树是否生成成功
	//并把结点元素信息存入最小生成树中
	for (int i = 0; i < n_vex - 1; i++) {
		if (flag[i].index_flag != flag[i + 1].index_flag) {
			free(edge_list);
			//销毁flag表
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
	//销毁flag表
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
