//#include<iostream>
//#include<vector>
//#include<queue>
//#define min(a,b) a<b?a:b
//using namespace std;
//int capacity[2004][2004],flow[2004][2004];
//struct node {
//	int k, s, j;
//
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
//		capacity[0][i] = 1;
//	}
//	for (int i = N+1; i <= N+N; i++)
//	{
//		graph[N+N+1].push_back(i);
//		graph[i].push_back(N+N+1);
//		capacity[i][N+N+1] = 2;
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
//					capacity[j + N][i] = 1;
//				}
//			}
//			else if (input[i].k >= input[j].k&&input[i].s >= input[j].s&&input[i].j >= input[j].j)
//			{
//				graph[i].push_back(j + N);
//				graph[j + N].push_back(i);
//				capacity[j + N][i] = 1;
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
//
//		total += amount;
//	}
//
//	printf("%d", total);
//
//
//}
//
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> graph[1001];
bool visit[1001];
int ans[1001];
struct node {
	int k, s, j;
};
bool serch(int now)
{
	if (visit[now])
		return 0;
	visit[now] = 1;
	for (int i = 0; i < graph[now].size(); i++)
	{
		int k = graph[now][i];
		if (ans[k] == 0 || serch(ans[k]))
		{
			ans[k] = now;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int N;
	scanf("%d", &N);

	vector<node> input(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d ", &input[i].k, &input[i].s, &input[i].j);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)continue;


			if (input[i].s == input[j].s&&input[i].j == input[j].j&&input[i].k == input[j].k)
			{
				if (i < j)
				{
					graph[i + 1].push_back(j + 1);
				}
			}
			else
			{
				if (input[i].s >= input[j].s&&input[i].j >= input[j].j&&input[i].k >= input[j].k)
				{
					graph[i + 1].push_back(j + 1);
				}
			}
		}
	}

	int cnt = 0;
	for (int j = 0; j < 2;j++)
	for (int i = 1; i <= N; i++)
	{
		memset(visit, 0, sizeof(visit));
		if (serch(i))
			cnt++;
	}

	printf("%d\n", N-cnt);

}