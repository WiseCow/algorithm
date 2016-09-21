#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int u[10001];
int cost[10001];
int lastcost[10001];
int main()
{
	int N;
	scanf("%d", &N);
	vector<int> in[10001];
	for (int i = 1; i <= N; i++)
	{

		int n, c;
		scanf("%d %d", &n, &c);
		u[i] = c;
		cost[i] = n;
		for (int l = 0; l < c; l++)
		{
			int t;
			scanf("%d", &t);
			in[t].push_back(i);
		}
	}
	priority_queue<int> q;
	for (int i = 1; i <= N; i++)
		if (u[i] == 0)
			q.push(i);


	while (q.size())
	{
		int now = q.top();
		q.pop();
		for (int i = 0; i < in[now].size(); i++)
		{
			u[in[now][i]]--;
			if(lastcost[in[now][i]] < cost[now] + lastcost[now])
			lastcost[in[now][i]] = cost[now] + lastcost[now];

			if (u[in[now][i]] == 0)
			{
				q.push(in[now][i]);
			}
		}
	}
	int maxx = 0;
	for (int i = 1; i <= N; i++)
	{
		if (maxx < lastcost[i] + cost[i])
			maxx = lastcost[i] + cost[i];
	}
	printf("%d", maxx);


	return 0;



}