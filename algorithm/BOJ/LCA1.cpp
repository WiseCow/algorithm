#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int>vc[50001];
int par[50001],de[50001];
int N,M;
void makede(int idx, int deep)
{
	if (de[idx]) return;
	de[idx] = deep;
	for (int i = 0; i < vc[idx].size(); i++)
	{
		int there = vc[idx][i];
		if (there != par[idx]&&!par[there])
		{
			par[there] = idx;
			makede(there, deep + 1);
		}
	}
}


int LCA(int a, int b)
{

	if (de[a] > de[b])
	{
		int k = de[a] - de[b];
		for (int i = 0; i < k; i++)
			a = par[a];
	}
	else if (de[b] > de[a])
	{
		int k = de[b] - de[a];
		for (int i = 0; i < k; i++)
			b = par[b];
	}
	while (a != b)
	{
		a = par[a];
		b = par[b];
	}
	return a;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i < N; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		vc[a].push_back(b);
		vc[b].push_back(a);
	}
	makede(1, 1);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", LCA(a, b));
	}
	return 0;

}