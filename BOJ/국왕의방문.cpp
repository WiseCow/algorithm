#include<cstdio>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;
int N, M, A, B, K, G,mat[1001][1001], gdist[1001][1001];
vector<vector<pair<int, int>>> edge;
vector<int> arr,dist;
int add(int here, int there, int t) {
	int st = gdist[here][there] - mat[here][there];
	int fi = gdist[here][there];
	t += K;
	if (t<st || t>fi)
		return 0;
	return fi - t;
}
int main()
{
	scanf("%d%d", &N, &M);
	scanf("%d%d%d%d", &A, &B, &K, &G);
	edge.resize(N + 1);
	arr.resize(G);
	dist.resize(N + 1);
	fill(dist.begin(), dist.end(), INF);
	for (int i = 0; i < G; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < M; i++)
	{
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		edge[a].push_back({ b,d });
		edge[b].push_back({ a,d });
		mat[a][b] = d;
		mat[b][a] = d;
	}
	int sum = 0;
	for (int i = 1; i < G; i++)
	{
		int start = arr[i - 1];
		int finish = arr[i];
		sum += mat[start][finish];
		gdist[start][finish] = sum;
		gdist[finish][start] = sum;
	}
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,A });
	dist[A] = 0;
	while (pq.size())
	{
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[now] < cost)
			continue;
		for (int i = 0; i < edge[now].size(); i++)
		{
			int there = edge[now][i].first;
			int there_cost = cost+edge[now][i].second + add(now,there,cost);
			if (dist[there] > there_cost)
			{
				dist[there] = there_cost;
				pq.push({ -there_cost,there });
			}
		}
	}
	printf("%d\n", dist[B]);

}
