#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector <int> edge[50001];
int pa[50001], de[50001];
int N,M,a,b;
void makedfs(int now, int parent, int deep)
{
	if (!de[now])
	{
		pa[now] = parent;
		de[now] = deep;
		for (int i = 0; i < edge[now].size(); i++)
			if (edge[now][i] != parent)
				makedfs(edge[now][i], now, deep + 1);
	}
}
int findLCA(int a, int b)
{
	int da = de[a], db = de[b];
	int na, nb;
	if (da > db)
	{
		na = a;
		nb = b;
		int cnt = da-db;
		while (cnt--)
			na = pa[na];
	}
	else if (da < db)
	{
		na = a; 
		nb = b;
		int cnt = db - da;
		while (cnt--)
			nb = pa[nb];
	}
	else
	{
		na = a;
		nb = b;
	}
	while (na != 1)
	{
		if (na == nb)
			return na;
		na = pa[na];
		nb = pa[nb];
		
	}
	return 1;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++)
	{
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	makedfs(1, 0, 1);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", findLCA(a, b));
	}




	return 0;


}