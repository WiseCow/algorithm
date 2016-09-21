#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>vc[10001];
int map[100001];
bool chk[100001];
int V, E,nn,c;

int dfs(int idx, bool root)
{
	map[idx] = nn++;
	int child = 0;
	int ret = map[idx];
	for (int i = 0; i < vc[idx].size(); i++)
	{
		int nidx = vc[idx][i];
		if (map[nidx] == -1)
		{
			child++;
			int sub = dfs(nidx, 0);
			if (!root&&sub >= map[idx])
				chk[idx] = 1;
			ret = min(ret, sub);
		}
		else
		{
			ret = min(ret, map[nidx]);
		}
	}
	if (root&&child >= 2)
		chk[idx] = 1;
	return  ret;
}

int main()
{
	scanf("%d%d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		vc[a].push_back(b);
		vc[b].push_back(a);
	}
	memset(map, -1, sizeof(map));
	for (int i = 1; i <= V; i++)
	if(map[i]==-1)
		dfs(i, 1);
	for (int i = 1; i <= V; i++)
		if (chk[i])
			c++;
	printf("%d\n", c);
	for (int i = 1; i <= V; i++)
		if (chk[i])
			printf("%d ", i);

}