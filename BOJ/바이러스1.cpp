#include <iostream>
using namespace std;
typedef struct GraphNode{
	int vertex;
	struct GraphNode *link;
} GraphNode;

GraphNode *adj[101];
int virus;
int visit[101];

void insert_node(int n1, int n2)
{
	GraphNode *w = NULL;
	GraphNode *node_n1 = new GraphNode;
	node_n1->vertex = n2;
	node_n1->link = NULL;
	GraphNode *node_n2 = new GraphNode;
	node_n2->vertex = n1;
	node_n2->link = NULL;

	if (adj[n1] == NULL)
		adj[n1] = node_n1;
	else {
		for (w = adj[n1]; w->link; w = w->link);
		w->link = node_n1;
	}
	if (adj[n2] == NULL)
		adj[n2] = node_n2;
	else {
		for (w = adj[n2]; w->link; w = w->link);
		w->link = node_n2;
	}
}

void dfs(GraphNode *head, int vertex)
{
	visit[vertex] = 1;
	GraphNode *w = NULL;
	for (w = head; w; w = w->link) {
		if (visit[w->vertex] == 0) {
			++virus;
			dfs(adj[w->vertex], w->vertex);
		}
	}
}

int main()
{
	int c, n, n1, n2, t_c, cnt = 1, i;
	cin>>t_c;
	while (t_c--) {
		cin>>c;
		cin>>n;
		while (n--) {
			cin>>n1>>n2;
			insert_node(n1, n2);
		}
		dfs(adj[1], 1);
		printf("#testcase%d\n", cnt++);
		printf("%d\n", virus);
		for (i = 0; i <= c; i++) {
			visit[i] = 0;
			adj[i] = NULL;
		}
		virus = 0;
	}
	return 0;
}