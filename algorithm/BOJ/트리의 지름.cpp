#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>> in[100001];
int dist[2][100001];

int maxc = 0;
int maxp = 0;
void dfs(int now, int cnt,bool visit[100001],bool flag)
{
	if (visit[now])return;
	else
	{
		visit[now] = 1;

		for (int k = 0; k < in[now].size(); k++)
		{
			if (dist[flag][in[now][k].first] == 0)
			{
				dist[flag][in[now][k].first] = cnt + in[now][k].second;
				if (maxc < dist[flag][in[now][k].first])
				{
					maxc = dist[flag][in[now][k].first];
					maxp = in[now][k].first;
				}
			}
			if (!visit[in[now][k].first])
				dfs(in[now][k].first, cnt + in[now][k].second, visit,flag);
		}
	}

}
int main()
{
	int V;
	scanf("%d", &V);

	for (int i = 1; i <= V; i++)
	{
		int N;
		scanf("%d", &N);
		int A,B;
		while (scanf("%d", &A))
		{
			if (A == -1)
				break;
			scanf("%d", &B);
			in[N].push_back({ A,B });
		}
	}
	bool visit[100001] = { 0 };
	dist[0][1] = 9999999;
	dfs(1,0, visit,0);
	int k = maxp;
	maxp = 0;
	maxc = 0;
	bool visit1[100001] = { 0 };
	dist[1][k] = 999999;
	dfs(k, 0, visit1, 1);

	printf("%d\n", maxc);
	return 0;


}