#include<cstdio>
#include<cstring>
#define mod 1000000000
int N;
int D[100][10][1 << 10];
int sol(int now, int idx,int use)
{
	if (now == N)
	{
		if (use == 1023)
			return 1;
		else
			return 0;
	}
	int &ret = D[now][idx][use];
	if (ret != -1)
		return ret;

	ret = 0;
	if (idx != 0)
		ret += sol(now + 1, idx - 1, use | 1 << (idx-1))%mod;
	if (idx != 9)
		ret += sol(now + 1, idx + 1, use | 1 << (idx + 1))%mod;
	return ret%mod;

}

int main()
{
	memset(D, -1, sizeof(D));

	scanf("%d", &N);

	long long cnt = 0;
	for (int i = 1; i < 10; i++)
	{
		cnt += sol(1, i,1<<i)%mod;
	}

	printf("%d", cnt%mod);

}