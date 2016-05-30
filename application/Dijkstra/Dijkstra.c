#include "Dijkstra.h"

dijkstra_shortest_path CreateDijkstraShorestPath(adj_list_dir_graph graph, int source)
{
	//作为返回值的最短路径表
	dijkstra_shortest_path path;
	path = (dijkstra_shortest_path) malloc(sizeof(struct dijkstra_shortest_path_s));
	if (!path) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	//每一个终点的最短路径
	path->source_index = source;
	path->destination_path = (struct dijkstra_destination_path_s *) malloc(sizeof(struct dijkstra_destination_path_s) * (graph->len - 1));
	if (!path->destination_path) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	//临时存放“已知最短路径结点”与“未知最短路径结点”之间的路径的链表
	linked_list tmp_path_list;
	tmp_path_list = LinkedListHeadInit();

	adj_list_dir_graph_adj_node * graph_pnode;
	//从tmp_index开始，依次访问各结点
	int tmp_index = source;
	//访问次数
	int i = 0;
	//创建bool型数组，存放结点是否已被访问
	bool * visited;
	visited = (bool *) malloc(sizeof(int) * graph->len);
	if (!visited) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	for (int i = 0; i < graph->len; i++)
		visited[i] = false;
	visited[source] = true;

	for (;;) {
		graph_pnode = graph->vex[tmp_index].first_adj;

		//把graph_pnode作为出结点的边，按权重从小到大存入临时链表
		while (graph_pnode != NULL) {
			if (visited[graph_pnode->adj_index] == false) {
				//weight为从起点到对应结点的路径权重之和
				int weight;
				if (i == 0)
					weight = graph_pnode->weight;
				else
					weight = graph_pnode->weight + path->destination_path[i - 1].weight;
				LinkedListHeadAdd(tmp_path_list, tmp_index, graph_pnode->adj_index, weight);
			}
			graph_pnode = graph_pnode->next_adj;
		}

		
		if (!LinkedListHeadEmpty(tmp_path_list)) {
			//选取权重最小的边，写入最短路径表
			path->destination_path[i].destination = tmp_path_list->next_path->in;
			path->destination_path[i].last_adj_index = tmp_path_list->next_path->out;
			path->destination_path[i].weight = tmp_path_list->next_path->weight;

			tmp_index = path->destination_path[i].destination;
			visited[tmp_index] = true;

			//删除临时链表中，包含已选取的结点的边
			LinkedListHeadDelete(tmp_path_list, tmp_path_list->next_path);
			linked_node * tmp_path_pnode;
			tmp_path_pnode = tmp_path_list->next_path;
			while (tmp_path_pnode != NULL) {
				if (tmp_path_pnode->in != tmp_index)
					tmp_path_pnode = tmp_path_pnode->next_path;
				else {
					linked_node * tmp = tmp_path_pnode->next_path;
					LinkedListHeadDelete(tmp_path_list, tmp_path_pnode);
					tmp_path_pnode = tmp;
				}
			}
		}

		i++;

		//判断循环是否继续，若已选取的点是否还有邻接点未被选取，或临时链表不为空，则继续
		if (!LinkedListHeadEmpty(tmp_path_list))
			continue;

		bool loop_continue = false;
		adj_list_dir_graph_adj_node * tmp_graph_pnode;
		tmp_graph_pnode = graph->vex[tmp_index].first_adj;

		while (tmp_graph_pnode != NULL) {
			if (visited[tmp_graph_pnode->adj_index] == false) {
				loop_continue = true;
				break;
			}
			tmp_graph_pnode = tmp_graph_pnode->next_adj;
		}
		if (!loop_continue)
			break;
	}

	//写入没有路径的点，把权重赋为0
	int j = 0;
	while (i < (graph->len - 1)) {
		if (visited[j] == false) {
			path->destination_path[i].destination = j;
			path->destination_path[i].last_adj_index = source;
			path->destination_path[i].weight = 0;
			i++;
		}
		j++;
	}

	free(visited);
	LinkedListHeadDestroy(&tmp_path_list);

	return path;
}

void PrintDijkstraShorestPath(adj_list_dir_graph graph, dijkstra_shortest_path path)
{
	int len = graph->len - 1;

	printf("起点\t终点\t权重\t路径\n");
	for (int i = 0; i < len; i++) {
		//如果权重为零，即没有路径时
		if (path->destination_path[i].weight == 0) {
			printf("%d\t%d\t%d\tNULL\n", path->source_index, path->destination_path[i].destination, path->destination_path[i].weight);
			continue;
		}

		//输出起点、终点、权重、路径的第一个点（即终点）
		printf("%d\t%d\t%d\t%d", path->source_index, path->destination_path[i].destination, path->destination_path[i].weight, path->destination_path[i].destination);
		int tmp = i;
		for (;;) {
			//循环输出路径后面的每一个点
			printf("<-%d", path->destination_path[tmp].last_adj_index);
			//如果找到起点就退出循环
			if (path->destination_path[tmp].last_adj_index == path->source_index)
				break;
			//找路径的前一个点
			for (int j = 0; j < i; j++)
				if (path->destination_path[tmp].last_adj_index == path->destination_path[j].destination)
					tmp = j;
		}
		printf("\n");
	}
	printf("\n");
}

void GetDijkstraPath(adj_list_dir_graph graph, int out, int in)
{
	//作为返回值的最短路径表
	dijkstra_shortest_path path;
	path = (dijkstra_shortest_path) malloc(sizeof(struct dijkstra_shortest_path_s));
	if (!path) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	//每一个终点的最短路径
	path->source_index = out;
	path->destination_path = (dijkstra_destination_path) malloc(sizeof(struct dijkstra_destination_path_s) * (graph->len - 1));
	if (!path->destination_path) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	//临时存放“已知最短路径结点”与“未知最短路径结点”之间的路径的链表
	linked_list tmp_path_list;
	tmp_path_list = LinkedListHeadInit();

	adj_list_dir_graph_adj_node * graph_pnode;
	//从tmp_index开始，依次访问各结点
	int tmp_index = out;
	//访问次数
	int i = 0;
	//创建bool型数组，存放结点是否已被访问
	bool * visited;
	visited = (bool *) malloc(sizeof(int) * graph->len);
	if (!visited) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	for (int i = 0; i < graph->len; i++)
		visited[i] = false;
	visited[out] = true;

	for (;;) {
		graph_pnode = graph->vex[tmp_index].first_adj;

		//把graph_pnode作为出结点的边，按权重从小到大存入临时链表
		while (graph_pnode != NULL) {
			if (visited[graph_pnode->adj_index] == false) {
				//weight为从起点到对应结点的路径权重之和
				int weight;
				if (i == 0)
					weight = graph_pnode->weight;
				else
					weight = graph_pnode->weight + path->destination_path[i - 1].weight;
				LinkedListHeadAdd(tmp_path_list, tmp_index, graph_pnode->adj_index, weight);
			}
			graph_pnode = graph_pnode->next_adj;
		}


		if (!LinkedListHeadEmpty(tmp_path_list)) {
			//选取权重最小的边，写入最短路径表
			path->destination_path[i].destination = tmp_path_list->next_path->in;
			path->destination_path[i].last_adj_index = tmp_path_list->next_path->out;
			path->destination_path[i].weight = tmp_path_list->next_path->weight;

			tmp_index = path->destination_path[i].destination;
			visited[tmp_index] = true;

			//如果刚写入最短路径表的入结点就是要求的入结点，则跳出循环
			if (tmp_index == in) {
				i++;
				break;
			}


			//删除临时链表中，包含已选取的结点的边
			LinkedListHeadDelete(tmp_path_list, tmp_path_list->next_path);
			linked_node * tmp_path_pnode;
			tmp_path_pnode = tmp_path_list->next_path;
			while (tmp_path_pnode != NULL) {
				if (tmp_path_pnode->in != tmp_index)
					tmp_path_pnode = tmp_path_pnode->next_path;
				else {
					linked_node * tmp = tmp_path_pnode->next_path;
					LinkedListHeadDelete(tmp_path_list, tmp_path_pnode);
					tmp_path_pnode = tmp;
				}
			}
		}

		i++;

		//判断循环是否继续，若已选取的点是否还有邻接点未被选取，或临时链表不为空
		if (!LinkedListHeadEmpty(tmp_path_list))
			continue;

		bool loop_continue = false;
		adj_list_dir_graph_adj_node * tmp_graph_pnode;
		tmp_graph_pnode = graph->vex[tmp_index].first_adj;

		while (tmp_graph_pnode != NULL) {
			if (visited[tmp_graph_pnode->adj_index] == false) {
				loop_continue = true;
				break;
			}
			tmp_graph_pnode = tmp_graph_pnode->next_adj;
		}
		if (!loop_continue)
			break;
	}

	if (path->destination_path[i - 1].weight == 0)
		printf("NULL\n");
	else {
		printf("%d", in);
		for (;;) {
			//循环输出路径后面的每一个点
			printf("<-%d", path->destination_path[i - 1].last_adj_index);
			//如果找到起点就退出循环
			if (path->destination_path[i - 1].last_adj_index == out)
				break;
			//找路径的前一个点
			for (int j = 0; j < i; j++)
				if (path->destination_path[i - 1].last_adj_index == path->destination_path[j].destination)
					i = j + 1;
		}
		printf("\n");
	}


	free(visited);
	LinkedListHeadDestroy(&tmp_path_list);
	DestroyDijkstraShorestPath(&path);
}

void DestroyDijkstraShorestPath(dijkstra_shortest_path * path)
{
	free((*path)->destination_path);
	free(*path);
	(*path) = NULL;
}

