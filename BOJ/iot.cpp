#include<cstdio>
#define max(a,b) ((a)>(b))?(a):(b)
int D, E, P, d, e,N, in[9][4];
int sol(int a, int b, int c, int aa, int bb, int cc, int cnt)
{
	int ret = 0;
	if (cnt == 0)
	{	
		ret = D*d + E*e;
		for (int i = 1; i <= N; i++)
		{
			ret = max(ret, sol(i, 0, 0, 1, 0, 0, 1));
		}
	}
	else if (cnt == 1)
	{
		int cpuc = D-in[a][0]*aa;
		int memc=E-in[a][1]*aa;
		int board = P - in[a][2] * aa;
		if (cpuc == 0 || memc == 0 || board == 0)
			return 0;
		ret = in[a][3] * aa + cpuc*d + memc*e;
		ret = max(ret, sol(a, 0, 0, aa + 1, 0, 0, 1));
		for (int i = 1; i <= N; i++)
			ret = max(ret, sol(a, i, 0, aa, 1, 0, 2));
	}
	else if (cnt == 2)
	{
		int cpuc = D - in[a][0] * aa- in[b][0] * bb;
		int memc = E - in[a][1] * aa- in[b][1] * bb;
		int board = P - in[a][2] * aa-in[b][2] * bb;
		if (cpuc == 0 || memc == 0 || board == 0)
			return 0;
		ret = in[a][3] * aa +in[b][3]*bb+ cpuc*d + memc*e;
		ret = max(ret, sol(a, b, 0, aa, bb+1, 0, 2));
		for (int i = 1; i <= N; i++)
			ret = max(ret, sol(a, b, i, aa, bb, 1, 3));
	}
	else
	{
		int cpuc = D - in[a][0] * aa - in[b][0] * bb - in[c][0] * cc;
		int memc = E - in[a][1] * aa - in[b][1] * bb - in[c][1] * cc;
		int board = P - in[a][2] * aa - in[b][2] * bb - in[c][2] * cc;
		if (cpuc == 0 || memc == 0 || board == 0)
			return 0;
		ret = in[a][3] * aa + in[b][3] * bb + in[c][3] * bb + cpuc*d + memc*e;
		ret = max(ret, sol(a, b, c, aa, bb, cc + 1, 3));
	}
	return ret;
}
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{
		scanf("%d %d %d %d %d", &D, &E, &P, &d, &e);
		scanf("%d", &N);
		for (int io = 1; io <= N; io++)
			scanf("%d %d %d %d", &in[io][0], &in[io][1], &in[io][2], &in[io][3]);
		printf("#%d ", itr + 1);
		printf("%d", sol(0, 0, 0, 0, 0, 0, 0));
	}
}

