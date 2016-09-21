#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int visit[20001];

bool nooo = 0;
void DFS(vector<int> ve[20001], int now,int nos)
{
	if (nooo == 1)
		return;

	if (visit[now]==0)
	{
		visit[now] = nos;
		for (int i = 0; i < ve[now].size(); i++)
		{
			DFS(ve, ve[now][i], -nos);
		}
	}
	else if (visit[now] != nos)
	{
		nooo = 1;
		return;
	}
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{
		int V, E;
		scanf("%d %d", &V, &E);
		vector<int> ve[20001];

		for (int i = 0; i < E; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			ve[a].push_back(b);
			ve[b].push_back(a);
		}
		
		nooo = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 1; i <= V; i++)
		{
			if(visit[i]==0)
				DFS(ve, i, 1);
			else
				DFS(ve, i, visit[i]);
		}
		if (nooo)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
