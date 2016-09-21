#include<cstdio>
#include<cstring>
#define inf -987654321
#define MAX(a,b) a>b?a:b
int N, M, t, D[101][101][2], in[101];
int sol(int gro, int now, bool flag)
{
	if (now >= N+1)
	{
		if(gro == M&&!flag)
			return 0;
		return inf;
	}
	int &ret = D[gro][now][flag];
	if (ret != -1)return ret;
	ret = inf;
	if (flag)
	{
		ret = MAX(ret, sol(gro, now + 1, 1) + in[now]);
		ret = MAX(ret, sol(gro + 1, now + 2, 0) + in[now]);
	}
	else
	{
		ret = MAX(ret, sol(gro, now + 1, 0));
		ret = MAX(ret, sol(gro, now + 1, 1) + in[now]);
		ret = MAX(ret, sol(gro+1, now + 2, 0) + in[now]);
	}
	return ret;
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &in[i]);
	}
	memset(D, -1, sizeof(D));
	printf("%d", sol(0, 1, 0));
}



//#include<cstdio>
//#define MAX(a,b) a>b?a:b
//int N, M, t, d[101][101], s[101];
//int solve(int e, int g)
//{
//	if (g == 0)return 0;
//	if (e <= 0) return -98765432;
//	if (d[e][g])return d[e][g];
//	int &res = d[e][g];
//	res = solve(e - 1, g);
//	for (int i = 1; i <= e; i++)res = MAX(res, solve(i - 2, g - 1) + s[e] - s[i - 1]);
//	return res;
//}
//int main()
//{
//	scanf("%d %d", &N, &M);
//	for (int i = 1; i <= N; i++)
//	{
//		scanf("%d", &t);
//		s[i] = s[i - 1] + t;
//	}
//	printf("%d", solve(N, M));
//}