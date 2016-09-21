#include<cstdio>
#include<cstring>
#define inf 987654321
#define min(a,b) ((a)<(b))?(a):(b)
int in[16][16];
int D[16][1 << 16];
int N;
int sol(int now, int visit,int st)
{
	if (visit == (1 << N) - 1)
	{
		if (in[now][st])
			return in[now][st];
		else
			return inf;
	}
	int &ret = D[now][visit];
	if (ret != -1)return ret;
	int t = inf;
	for (int i = 0; i < N; i++)
	{
		if (in[now][i] != 0 && !(visit&(1 << i)))
			t = min(t, sol(i, visit | (1 << i), st)+in[now][i]);
	}
	ret = t;
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &in[i][j]);
	memset(D, -1, sizeof(D));
	printf("%d",sol(0, 1,0));
}