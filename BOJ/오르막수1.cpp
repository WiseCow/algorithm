#include<cstdio>
#define MOD 10007
int D[1002][10];
int sum[1002];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 10; i++)
		D[1][i] = 1;
	sum[1] = 10;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int ssum = 0;
			for (int k = j; k < 10; k++)
			{
				ssum += D[i - 1][k];
				ssum %= MOD;
			}
			D[i][j] = ssum;
			sum[i] =(sum[i] + ssum)%MOD;
		}
	}
	printf("%d", sum[n]);
}
