#include<cstdio>
#define MOD 1000000000
long long D[10][101];
long long sum[101];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i < 10; i++)D[i][1] = 1;
	sum[1] = 9;
	for (int i = 2; i <= N; i++)
		for (int j = 0; j < 10; j++)
		{
			if (j != 0)
				D[j][i] = (D[j][i]+D[j - 1][i - 1])%MOD;
			if(j!=9)
				D[j][i] = (D[j][i] + D[j + 1][i - 1]) % MOD;
			sum[i] = (sum[i] + D[j][i]) % MOD;
		}
	printf("%lld", sum[N]);
}[]