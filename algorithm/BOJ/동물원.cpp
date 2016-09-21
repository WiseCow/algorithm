#include<cstdio>
#include<cstring>
#define MOD 9901
int D[3][100001], n;
int sol(int use, int now)
{
	if (now == n)return 1;
	if (now > n)return 0;
	int &ret = D[use][now];
	if (ret != -1)return ret;
	ret = 0;
	if (use == 0)
	{
		ret = (ret + sol(0, now + 1)) % MOD;
		ret = (ret + sol(1, now + 1)) % MOD;
		ret = (ret + sol(2, now + 1)) % MOD;
	}
	else if (use == 1)
	{
		ret = (ret + sol(0, now + 1)) % MOD;
		ret = (ret + sol(2, now + 1)) % MOD;
	}
	else if (use == 2)
	{
		ret = (ret + sol(0, now + 1)) % MOD;
		ret = (ret + sol(1, now + 1)) % MOD;
	}
	return ret;
}
int main()
{
	scanf("%d", &n);
	memset(D, -1, sizeof(D));
	printf("%d", sol(0, 0));
}