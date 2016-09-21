#include<cstdio>
#include<queue>
#include<vector>
#define min(a,b) ((a)>(b))?b:a
using namespace std;
vector<pair<int, int>> in[100001];
int cost[100001];
int main()
{
	int N, M,st,en, a, b, c;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		in[a].push_back({ b,c });
		in[b].push_back({ a,c });
	}
	scanf("%d %d", &st, &en);
	queue<int>q;
	q.push(st);
	while (q.size())
	{
		int now = q.front();
		q.pop();
		for (auto a:in[now])
		{
			int to = a.first;
			int dist = a.second;
			if(cost[now])
				dist = min(cost[now], dist);
			if (cost[to] < dist)
			{
				cost[to] = dist;
				q.push(to);
			}
		}
	}
	printf("%d\n",cost[en]);
}