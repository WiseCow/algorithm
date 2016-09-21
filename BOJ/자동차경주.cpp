#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int N, M;
vector < vector<pair<int, int>>> Edge;
int dist[1001];
int par[1001];
int main()
{
	scanf("%d%d", &N, &M);
	Edge.resize(N+1);
	for (int i = 0; i < M; i++)
	{
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		Edge[a].push_back({ b,-d });
	}
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });
	while (pq.size())
	{
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (now == 1 && cost != 0)
			continue;
		if (dist[now] < cost)
			continue;
		for (int i = 0; i < Edge[now].size(); i++)
		{
			int there = Edge[now][i].first;
			int there_cost = Edge[now][i].second+cost;
			if (dist[there] > there_cost)
			{
				dist[there] = there_cost;
				par[there] = now;
				pq.push({ -there_cost,there });
			}
		}
	}
	printf("%d\n", -dist[1]);
	stack<int >st;
	int now = 1;
	while(1)
	{
		st.push(now);
		now = par[now];
		if (now == 1)
		{
			st.push(1);
			break;
		}
	}

	while (st.size())
	{
		printf("%d ", st.top());
		st.pop();
	}
}