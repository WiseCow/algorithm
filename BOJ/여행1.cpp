#include<cstdio>
#include<cstring>
#define max(a,b) a>b?a:b
int dis[301][301], N, M, K, D[302][302];
int sol(int now, int use)
{
	if (now == N)
		return 0;
	int &ret = D[now][use];
	if (ret != -1)
		return ret;
	ret = 0;

	for (int i = now + 1; i <= N; i++)
	{
		if (dis[now][i] != 0 && use + 1 < M||(use+1==M&&i==N))
			ret = max(ret, sol(i, use + 1) + dis[now][i]);
	}
	return ret;
}
int main()
{
	scanf("%d%d%d", &N, &M, &K);
	memset(D, -1, sizeof(D));

	for (int i = 0; i < K; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (dis[a][b]<c)
			dis[a][b] = c;
	}

	printf("%d", sol(1, 1));
}