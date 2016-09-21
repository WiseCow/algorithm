#include<cstdio>
#include<cstring>
#define MAX(a,b) a>b?a:b
int N, map[50001], K,a,DP[50001][3];
int sol(int i, int sel)
{
	if (sel == 3)return 0;
	if (i >= N)return 0;

	int &ret = DP[i][sel];
	if (ret != -1)return ret;
	ret = 0;

	if (i + K - 1 <= N)
	{
		int sum = map[i + K - 1] - map[i - 1];
		ret = MAX(ret, sum + sol(i + K, sel + 1));
	}
	ret = MAX(ret, sol(i + 1, sel));
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a);
		map[i] = map[i - 1] + a;
	}
	scanf("%d", &K);
	memset(DP, -1, sizeof(DP));
	printf("%d", sol(1, 0));
	return 0;
}