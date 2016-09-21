#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int N,cap[1000][1000],flow[1000][1000],par[1000];
bool trip[1000];
int source, sink;

map<string, int> h;
int makenum(string str)
{
	if (h.count(str) > 0)
		return h[str];
	int cnt = h.size();
	return h[str] = cnt + 1;
}

int bfs()
{
	queue<int>q;
	q.push(source);
	trip[source] = 1;
	while (q.size())
	{
		int now = q.front();
		q.pop();
		for (int i = 1; i <= h.size(); i++)
		{
			if (cap[now][i] - flow[now][i]>0 && !trip[i])
			{
				par[i] = now;
				q.push(i);
				trip[i] = 1;
			}
		}
	}
	if (!trip[sink])
		return 0;
	int tmp = sink;
	int amount = 0x3f3f3f3f;
	while (par[tmp] != -1)
	{
		amount = min(amount, cap[par[tmp]][tmp] - flow[par[tmp]][tmp]);
		tmp = par[tmp];
	}
	tmp = sink;
	while (par[tmp] != -1) 
	{
		flow[par[tmp]][tmp] += amount;
		flow[tmp][par[tmp]] -= amount;
		tmp = par[tmp];
	}
	return amount;
}
int sol()
{
	int n = h.size();
	int ret = 0;
	while (1)
	{
		memset(par, -1, sizeof(par));
		memset(trip, 0, sizeof(trip));
		int f = bfs();
		if (f == 0)
			break;
		ret += f;
	}
	return ret;

}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		string a, b;
		int c;
		cin >> a >> b >> c;
		int u = makenum(a);
		int v = makenum(b);
		cap[u][v] += c;
		cap[v][u] += c;
	}
	source = makenum("A");
	sink = makenum("Z");
	printf("%d", sol());
}
