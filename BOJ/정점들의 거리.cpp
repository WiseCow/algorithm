#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<pair<int, int>>vc[40001];
int N, M, pa[40001][16], de[40001], co[40001];

void makede(int now, int deep, int cost)
{

	if (de[now]) return;
	de[now] = deep;
	for (int i = 0; i < vc[now].size(); i++)
	{
		int there = vc[now][i].first;
		int cc = vc[now][i].second;
		if (there != pa[now][1] && !pa[there][1])
		{
			pa[there][1] = now;
			for (int i = 1; i < 15; i++)
				pa[there][i + 1] = pa[now][i];
			co[there] = cost + cc;
			makede(there, deep + 1, cost + cc);
		}
	}
}
int LCA(int a, int b)
{
	int ra = a, rb = b;
	if (de[a] > de[b])
	{
		int k = de[a] - de[b];
		while (k != 0)
		{
			if (k >= 10)
			{
				a = pa[a][10];
				k -= 10;
			}
			else
			{
				a = pa[a][k];
				k = 0;
			}
		}
	}
	else if (de[b] > de[a])
	{
		int k = de[b] - de[a];
		while (k != 0)
		{
			if (k >= 10)
			{
				b = pa[b][10];
				k -= 10;
			}
			else
			{
				b = pa[b][k];
				k = 0;
			}
		}
	}

	if (a == b)
		return co[ra] + co[rb] - co[a] * 2;
	else
	{
		while (a != b)
		{
			a = pa[a][1];
			b = pa[b][1];
		}
	}

	return co[ra] + co[rb] - co[a] * 2;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i < N; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		vc[a].push_back({ b,c });
		vc[b].push_back({ a,c });
	}
	makede(1, 1, 0);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", LCA(a, b));
	}
}