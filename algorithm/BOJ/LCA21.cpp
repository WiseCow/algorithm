#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int N,pa[100001][17],de[100001],M;
vector< int> vc[100001];
void dfs(int now, int parent, int dep) {
	de[now] = dep;
	for (int i = 0; i<vc[now].size(); i++) {
		int there = vc[now][i];
		if (there == parent)
			continue;
		pa[there][0] = now;
		for (int i = 1; i<17; i++)
			pa[there][i] = pa[pa[there][i - 1]][i - 1];
		dfs(there, now, dep + 1);
	}

}
int lca(int a, int b) {
	if (de[a]<de[b])
		swap(a, b);
	for (int i = 16; i >= 0; i--) {
		if ((1 << i) <= de[a] - de[b]) {
			a = pa[a][i];
		}
	}
	if (a == b)
		return a;
	for (int i = 16; i >= 0; i--) {
		if (pa[a][i] != pa[b][i]) {
			a = pa[a][i];
			b = pa[b][i];
		}
	}
	return pa[a][0];
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

	dfs(1, 0,1);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", lca(a, b));
	}
}