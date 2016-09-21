#include<cstdio>
#include<cstring>
#define MAX(a,b) a>b?a:b
int C, map[50001], K,DP[50001][3];

int sol(int i, int sel)
{
	if (sel == 3)
		return 0;

	if (i >= C)
		return 0;

	int &ret = DP[i][sel];
	if (ret != -1)return ret;
	ret = 0;
	if (i + K-1 <= C)
	{
		int sum = map[i + K - 1] - map[i-1];
		ret = MAX(ret, sum + sol(i + K, sel + 1));
	}


	ret = MAX(ret, sol(i + 1, sel));
	return ret;
}
int main()
{
	scanf("%d ", &C);
	for (int i = 1; i <= C; i++)
	{
		int a;
		scanf("%d", &a);
		map[i] = map[i - 1] + a;
		
	}
	memset(DP, -1, sizeof(DP));
	scanf("%d", &K);

	printf("%d", sol(1,0));
	return 0;
}