#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> in[1001];
int visit[1001];
int visitd[1001];

void dfs(int i)
{
	if (!visit[i])
	{
		visit[i] = 1;
		printf("%d ", i);
		for (int j = 0; j < in[i].size(); j++)
		{
			dfs(in[i][j]);
		}
	}
}
void bfs(int i)
{
	queue<int>q;

	q.push(i);
	while (q.size())
	{
		int a = q.front();
		q.pop();
		if(!visitd[a])
		{
			visitd[a] = 1;
			printf("%d ", a);
			for (int j = 0; j < in[a].size(); j++)
			{
				if (!visitd[in[a][j]])
					q.push(in[a][j]);
			}
		}
	}
}

int main()
{
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);

	


	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		in[a].push_back(b);
		in[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
	{
		sort(in[i].begin(), in[i].end());
		in[i].erase(unique(in[i].begin(), in[i].end()), in[i].end());
	}

	dfs(V);
	printf("\n");
	bfs(V);




	return 0;
}