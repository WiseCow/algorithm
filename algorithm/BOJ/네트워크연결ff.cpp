#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

struct Edge
{
	int start;
	int end;
	int cost;
	Edge() {}
	Edge(int a, int b, int c) {
		start = a; end = b; cost = c;
	}
	bool operator<(const Edge &other)const
	{
		return cost > other.cost;
	}
};
int main()
{ 
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);
	vector<pair<int, int>> ve[1001];
	for (int i = 0; i < M; i++)
	{
		int a, s, d;
		scanf("%d %d %d", &a, &s, &d);
		ve[a].push_back({ s,d });
		ve[s].push_back({ a,d });
	}
	

	int ans = 0;
	bool  visit[1001] = { 0 };
	visit[1] = 1;
	priority_queue <Edge> q;
	for (int i = 0; i < ve[1].size(); i++)
		q.push(Edge(1, ve[1][i].first, ve[1][i].second));

	for (int i = 1; i < N; i++)
	{
		Edge tmp;
		while (q.size())
		{
			tmp = q.top();
			q.pop();
			if (!visit[tmp.end])
				break;
		}
		ans += tmp.cost;
		visit[tmp.end] = 1;

		for (int i = 0; i < ve[tmp.end].size(); i++)
		{
			q.push(Edge(tmp.end, ve[tmp.end][i].first, ve[tmp.end][i].second));
		}
	}

	printf("%d\n", ans);

}