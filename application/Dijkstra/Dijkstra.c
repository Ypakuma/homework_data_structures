#include "Dijkstra.h"

dijkstra_shortest_path CreateDijkstraShorestPath(adj_list_dir_graph graph, int source)
{
	//��Ϊ����ֵ�����·����
	dijkstra_shortest_path path;
	path = (dijkstra_shortest_path) malloc(sizeof(struct dijkstra_shortest_path_s));
	if (!path) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	//ÿһ���յ�����·��
	path->source_index = source;
	path->destination_path = (struct dijkstra_destination_path_s *) malloc(sizeof(struct dijkstra_destination_path_s) * (graph->len - 1));
	if (!path->destination_path) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	//��ʱ��š���֪���·����㡱�롰δ֪���·����㡱֮���·��������
	linked_list tmp_path_list;
	tmp_path_list = LinkedListHeadInit();

	adj_list_dir_graph_adj_node * graph_pnode;
	//��tmp_index��ʼ�����η��ʸ����
	int tmp_index = source;
	//���ʴ���
	int i = 0;
	//����bool�����飬��Ž���Ƿ��ѱ�����
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

		//��graph_pnode��Ϊ�����ıߣ���Ȩ�ش�С���������ʱ����
		while (graph_pnode != NULL) {
			if (visited[graph_pnode->adj_index] == false) {
				//weightΪ����㵽��Ӧ����·��Ȩ��֮��
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
			//ѡȡȨ����С�ıߣ�д�����·����
			path->destination_path[i].destination = tmp_path_list->next_path->in;
			path->destination_path[i].last_adj_index = tmp_path_list->next_path->out;
			path->destination_path[i].weight = tmp_path_list->next_path->weight;

			tmp_index = path->destination_path[i].destination;
			visited[tmp_index] = true;

			//ɾ����ʱ�����У�������ѡȡ�Ľ��ı�
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

		//�ж�ѭ���Ƿ����������ѡȡ�ĵ��Ƿ����ڽӵ�δ��ѡȡ������ʱ����Ϊ�գ������
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

	//д��û��·���ĵ㣬��Ȩ�ظ�Ϊ0
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

	printf("���\t�յ�\tȨ��\t·��\n");
	for (int i = 0; i < len; i++) {
		//���Ȩ��Ϊ�㣬��û��·��ʱ
		if (path->destination_path[i].weight == 0) {
			printf("%d\t%d\t%d\tNULL\n", path->source_index, path->destination_path[i].destination, path->destination_path[i].weight);
			continue;
		}

		//�����㡢�յ㡢Ȩ�ء�·���ĵ�һ���㣨���յ㣩
		printf("%d\t%d\t%d\t%d", path->source_index, path->destination_path[i].destination, path->destination_path[i].weight, path->destination_path[i].destination);
		int tmp = i;
		for (;;) {
			//ѭ�����·�������ÿһ����
			printf("<-%d", path->destination_path[tmp].last_adj_index);
			//����ҵ������˳�ѭ��
			if (path->destination_path[tmp].last_adj_index == path->source_index)
				break;
			//��·����ǰһ����
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
	//��Ϊ����ֵ�����·����
	dijkstra_shortest_path path;
	path = (dijkstra_shortest_path) malloc(sizeof(struct dijkstra_shortest_path_s));
	if (!path) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}
	//ÿһ���յ�����·��
	path->source_index = out;
	path->destination_path = (dijkstra_destination_path) malloc(sizeof(struct dijkstra_destination_path_s) * (graph->len - 1));
	if (!path->destination_path) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	//��ʱ��š���֪���·����㡱�롰δ֪���·����㡱֮���·��������
	linked_list tmp_path_list;
	tmp_path_list = LinkedListHeadInit();

	adj_list_dir_graph_adj_node * graph_pnode;
	//��tmp_index��ʼ�����η��ʸ����
	int tmp_index = out;
	//���ʴ���
	int i = 0;
	//����bool�����飬��Ž���Ƿ��ѱ�����
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

		//��graph_pnode��Ϊ�����ıߣ���Ȩ�ش�С���������ʱ����
		while (graph_pnode != NULL) {
			if (visited[graph_pnode->adj_index] == false) {
				//weightΪ����㵽��Ӧ����·��Ȩ��֮��
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
			//ѡȡȨ����С�ıߣ�д�����·����
			path->destination_path[i].destination = tmp_path_list->next_path->in;
			path->destination_path[i].last_adj_index = tmp_path_list->next_path->out;
			path->destination_path[i].weight = tmp_path_list->next_path->weight;

			tmp_index = path->destination_path[i].destination;
			visited[tmp_index] = true;

			//�����д�����·������������Ҫ������㣬������ѭ��
			if (tmp_index == in) {
				i++;
				break;
			}


			//ɾ����ʱ�����У�������ѡȡ�Ľ��ı�
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

		//�ж�ѭ���Ƿ����������ѡȡ�ĵ��Ƿ����ڽӵ�δ��ѡȡ������ʱ����Ϊ��
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
			//ѭ�����·�������ÿһ����
			printf("<-%d", path->destination_path[i - 1].last_adj_index);
			//����ҵ������˳�ѭ��
			if (path->destination_path[i - 1].last_adj_index == out)
				break;
			//��·����ǰһ����
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

