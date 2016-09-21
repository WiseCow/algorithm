#include<iostream>
#include<queue>
#include<vector>
#define min(a,b) (a)<(b)?(a):(b)
using namespace std;
int capacity[300][300] = { 0 }, flow[300][300] = { 0 };
int main()
{

	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> graph[300];
	for (int i = 1; i <= n; i++)
	{
		graph[0].push_back(i);
		graph[i].push_back(0);
		capacity[0][i] = 1;
	}
	for (int i = n+1; i <= n+n+1; i++)
	{
		graph[i].push_back(n+n+1);
		graph[n+n+1].push_back(i);
		capacity[i][n+n+1] = 1;
	}
	for (int itr = 0; itr < m; itr++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b + n);
		graph[b + n].push_back(a);
		capacity[a][b + n] = 1;
	}
	int src = 0, sink = n + n + 1, total = 0;

	
	while(1)
	{
		queue<int>q;
		q.push(src);
		int parent[300]  = { 0 };

		while (parent[sink] == 0 && q.size())
		{
			int here = q.front();
			q.pop();
			for (int itr = 0; itr < graph[here].size(); itr++)
			{
				int there = graph[here][itr];
				int capa = capacity[here][there] - flow[here][there];
				if (capa > 0 && parent[there] == 0)
				{
					q.push(there);
					parent[there] = here;
				}
			}
		}
		if (parent[sink] == 0)
			break;
		int amount = 987654321;

		for (int p = sink; p != src; p = parent[p])
		{
			amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
		}
		for (int p = sink; p != src; p = parent[p])
		{
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		total += amount;
	}

	printf("%d", total);

}