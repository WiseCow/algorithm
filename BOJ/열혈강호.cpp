#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
vector<int> in[1001];
bool visit[1001];
int res[1001];
bool serch(int now)
{
	if (visit[now])return 0;
		visit[now] = 1;
	for (int i = 0; i < in[now].size(); i++)
	{
		int k = in[now][i];
		if (res[k]==0 || serch(res[k]))
		{
			res[k] = now;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		int a;
		scanf("%d", &a);
		for (int k = 0; k < a; k++)
		{
			int l;
			scanf("%d", &l);
			in[i].push_back(l);
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		memset(visit, 0, sizeof(visit));
		if (serch(i))
			ans++;
	}

	printf("%d\n",ans);


}