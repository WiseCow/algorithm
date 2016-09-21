#include<cstdio>
#include<cstring>
int in[100001];
int group[100001];
int find(int now, int start,bool chk,bool visit[100001])
{
	if (group[now])return 0;
	if (now == start)
	{
		if (chk)
		{
			chk = 0;
			visit[now] = 1;
			int a=find(in[now], start, chk,visit);
			group[now] = a > 0 ? 1 : -1;
		}
		else
			return true;
	}
	else
	{
		if (visit[now])return false;
			visit[now] = 1;
		int a= find(in[now], start, chk,visit);
		group[now]= a > 0 ? 1 : -1;
	}
	return group[now];

}
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{
		int n;
		scanf("%d", &n);

		memset(group, 0, sizeof(group));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &in[i]);
			if (i == in[i])
				group[i] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			bool visit[100000] = { 0 };
			find(i, i, 1, visit);
		}
		int cnt = 0;

		for (int i = 1; i <= n; i++)
			if (group[i] == -1)cnt++;
		printf("%d\n", cnt);
	}
}