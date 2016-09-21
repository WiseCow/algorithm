#include<cstdio>
#include<cstring>
#define MAX(a,b) a>b?a:b
int N;
int map[2][2001], DP[2001][2001];
int sol(int L, int R)
{
	if (L > N || R > N)return 0;


	int &ret = DP[L][R];
	if (ret != -1)return ret;
	ret = 0;
	if (map[0][L] > map[1][R])
	{
		ret = MAX(ret, map[1][R] + sol(L, R + 1));
	}
	ret = MAX(ret, sol(L+1, R));
	ret = MAX(ret, sol(L + 1, R+1));
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)scanf("%d", &map[0][i]);
	for (int i = 1; i <= N; i++)scanf("%d", &map[1][i]);
	memset(DP, -1, sizeof(DP));
	printf("%d", sol(1, 1));
}