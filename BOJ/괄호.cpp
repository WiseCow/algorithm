#include<cstdio>
#define mod 1000000007
long long  D[2501];
int main()
{
	int T;
	scanf("%d", &T);
	D[0] = 1;
	D[1] = 1;
	for (int i = 2; i <= 2500; i++)
	{
		for (int j = 0; j < i; j++)
		{
			D[i] += D[j] * D[i - j - 1];
			D[i] %= mod;
		}
	}
	int res;
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &res);
		printf("%d\n", !(res % 2) ? D[res / 2] : 0);
	}
	return 0;
}