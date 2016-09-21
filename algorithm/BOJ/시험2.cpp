//#include<iostream>
//#include<vector>
//#include<queue>
//#define min(a,b) a<b?a:b
//using namespace std;
//int capacity[2004][2004],flow[2004][2004];
//struct node {
//	int k, s, j;
//};
//int main()
//{
//	int N;
//	scanf("%d", &N);
//	vector<node> input(N);
//	vector<int> graph[2004];
//	for (int i = 0; i < N; i++)
//		scanf("%d %d %d", &input[i].k, &input[i].s, &input[i].j);
//
//	for (int i = 1; i <= N; i++)
//	{
//		graph[0].push_back(i);
//		graph[i].push_back(0);
//		capacity[0][i] = 2;
//
//	}
//	for (int i = N+1; i <= N+N; i++)
//	{
//		graph[N+N+1].push_back(i);
//		graph[i].push_back(N+N+1);
//		capacity[i][N+N+1] = 1;
//	}
//
//	for (int i = 1; i < N; i++)
//	{
//		for (int j = 1; j < N; j++)
//		{
//			if (i == j)
//				continue;
//			if (input[i].k == input[j].k&&input[i].s == input[j].s&&input[i].j == input[j].j)
//			{
//				if (i < j)
//				{
//					graph[i].push_back(j + N);
//					graph[j + N].push_back(i);
//					capacity[i][j+N] = 1;
//				}
//			}
//			else if (input[i].k >= input[j].k&&input[i].s >= input[j].s&&input[i].j >= input[j].j)
//			{
//				graph[i].push_back(j + N);
//				graph[j + N].push_back(i);
//				capacity[i][j+N] = 1;
//			}
//		}
//	}
//
//	int src = 0, sink = N + N + 1,total = 0;
//
//	while (1)
//	{
//		queue<int>q;
//		q.push(src);
//		int parent[2004] = { 0 };
//		while (parent[sink] == 0 && q.size())
//		{
//			int here = q.front();
//			q.pop();
//
//			for (int itr = 0; itr < graph[here].size(); itr++)
//			{
//				int there = graph[here][itr];
//				int capa = capacity[here][there] - flow[here][there];
//				if (capa > 0 && parent[there] == 0)
//				{
//					parent[there] = here;
//					q.push(there);
//				}
//			}
//		}
//		if (parent[sink] == 0) break;
//		int amount=987654321;
//
//
//		for (int p = sink; p != src; p = parent[p])
//		{
//			amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
//		}
//		for (int p = sink; p != src; p = parent[p])
//		{
//			flow[parent[p]][p] += amount;
//			flow[p][parent[p]] -= amount;
//		}
//		total += amount;
//	}
//
//	printf("%d", total);
//}
//
//
//

#include<iostream>
#include<vector>
using namespace std;
struct Edge { int k, s, j; };
vector<int> gra[1002];
int ans[1002];
bool dfs(int now, bool visit[1002])
{
	if (visit[now])
		return 0;
	visit[now] = 1;
	for (int i = 0; i < gra[now].size(); i++)
	{
		int next = gra[now][i];
		if (!ans[next] || dfs(ans[next],visit))
		{
			ans[next] = now;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int N;
	scanf("%d", &N);
	vector<Edge> vc(N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &vc[i].k, &vc[i].s, &vc[i].j);
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				continue;
			if (vc[i].k == vc[j].k&&vc[i].s == vc[j].s&&vc[i].j == vc[j].j)
			{
				if(i<j)
				gra[i+1].push_back(j+1);
			}
			else if (vc[i].k >= vc[j].k&&vc[i].s >= vc[j].s&&vc[i].j >= vc[j].j)
			{
				gra[i+1].push_back(j+1);
			}
		}
	}

	int rst = 0;
	for (int j = 0; j < 2;j++)
	for (int i = 1; i <= N; i++)
	{
		bool visit[1002] = { 0 };
		rst+=dfs(i, visit);
	}

	printf("%d", rst);
}