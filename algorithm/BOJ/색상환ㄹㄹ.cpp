#include <cstdio>
#define mod 1000000003
int d[1002][1002];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	d[0][0] = d[1][0] = d[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= i / 2 + 3; j++)
		{
			if (j == 0)
				d[i][j] = 1;
			else
				d[i][j] = (d[i - 1][j] + d[i - 2][j - 1]) % mod;
		}
	}

	printf("%d\n", (d[n - 3][k - 1] + d[n - 1][k]) % mod);
	return 0;
}