#include<cstdio>
#include<cstring>
long long D[101];
long long sol(int n)
{
	if (n == 0)return 1;
	long long &ret = D[n];
	if (ret != -1)return ret;
	ret = sol(n - 1) + sol(n - 5);
	return ret;
}

int main()
{
	int tc;
	scanf("%d", &tc);
	memset(D, -1, sizeof(D));
	D[1] = D[2] = D[3] = 1;
	D[4] = D[5] = 2;
	for (int i = 0; i < tc; i++)
	{
		int t;
		scanf("%d", &t);
		printf("%lld\n", sol(t));
	}


}