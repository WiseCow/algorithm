#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int N, M,K;
vector<vector<pair<int, int>>>edge;
int main()
{
	scanf("%d%d%d", &N, &M, &K);
	edge.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		edge[a].push_back({ b,d });
	}
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,1 });
	vector<priority_queue<int>> dist(N + 1);
	dist[1].push(0);
	while (pq.size())
	{
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		for (int i = 0; i < edge[now].size(); i++)
		{
			int there = edge[now][i].first;
			int there_cost = edge[now][i].second + cost;
			if (dist[there].size() < K)
			{
				pq.push({ -there_cost,there });
				dist[there].push(there_cost);
			}
			else if (dist[there].top() > there_cost)
			{
				dist[there].pop();
				dist[there].push(there_cost);
				pq.push({ -there_cost,there });
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (dist[i].size() != K)
			printf("-1\n");
		else
			printf("%d\n", dist[i].top());
	}
}