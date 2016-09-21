#include<cstdio>
using namespace std;
int N, K, dp[2][10001], in[101];
int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++)scanf("%d", &in[i]);
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int k = 0; k <= K; k++)
			dp[i & 1][k] = dp[(i - 1) & 1][k];
		for (int k = in[i]; k <= K; k++)
			dp[i & 1][k] += dp[i & 1][k - in[i]];
	}
	printf("%d", dp[N & 1][K]);
}
