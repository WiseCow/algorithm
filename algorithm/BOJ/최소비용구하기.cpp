#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
vector<vector<pair<int,int>>>gra;
int n, m;
int map[1001];
int dist(int s,int f)
{
	memset(map, 0x7f, sizeof(map));
	map[s] = 0;
	queue <int> q;
	q.push(s);
	
	while (q.size())
	{
		int here = q.front();
		q.pop();
		for (int i = 0; i < gra[here].size(); i++)
		{
			int there = gra[here][i].first;
			int cost = gra[here][i].second;
			if (map[there] > map[here] + cost)
			{
				map[there] = map[here] + cost;
				q.push(there);
			}
		}
	}
	return map[f];
}
int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++)
	{
		vector<pair<int,int>> v;
		gra.push_back(v);
	}

	for (int i = 0; i < m; i++)
	{
		int v1, v2, d;
		scanf("%d %d %d", &v1, &v2, &d);
		gra[v1].push_back({ v2,d });
	}
	int s, f;
	scanf("%d %d", &s, &f);

	printf("%d", dist(s, f));
}