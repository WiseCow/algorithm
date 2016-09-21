#include<cstdio>
#include<cstring>
#define MOD 10007
int DP[1001], N;

int sol(int i)
{
	if (i == 1) return 1;
	if (i == 2) return 3;
	if (i == 3) return 5;
	int &ret = DP[i];
	if (ret != -1)return ret;
	ret = (sol(i - 1) + sol(i - 2)*2) % MOD;
	return ret;
}
int main()
{
	scanf("%d", &N);
	memset(DP, -1, sizeof(DP));
	printf("%d", sol(N));
}
