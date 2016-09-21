#include<iostream>
#include<queue>
#include<vector>
#define INF 987654321
using namespace std;
int cost[20001];

int main()
{
	int V, E;
	scanf("%d %d", &V, &E);
	for (int i = 1; i <= V; i++)
		cost[i] = INF;
	int Start;
	scanf("%d", &Start);
	vector<pair<int, int>> in[20001];
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		in[a].push_back({ b,c });
	}
	queue<int> a;
	for (int i = 0; i < in[Start].size(); i++)
	{
		if (cost[in[Start][i].first]>in[Start][i].second)
		{
			cost[in[Start][i].first] = in[Start][i].second;
			a.push(in[Start][i].first);
		}
	}

	while (!a.empty())
	{
		int p = a.front();
		a.pop();

		for (int i = 0; i < in[p].size(); i++)
		{
			if(cost[in[p][i].first]>(cost[p]+in[p][i].second))
			{
				cost[in[p][i].first] = cost[p] + in[p][i].second;
				a.push(in[p][i].first);
			}
		
		}
	}
	cost[Start] = 0;

	for (int i = 1; i <= V; i++)
	{
		if (cost[i] != INF)
			printf("%d\n", cost[i]);
		else
			printf("INF\n");
	}


	return 0;
}