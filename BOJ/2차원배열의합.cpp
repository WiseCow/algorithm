#include<cstdio>
#include<cstring>
int D[301][301];
int N, M;
int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &D[i][j]);
			D[i][j] += D[i][j - 1];
		}
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int ans = 0;
		for (int q = a; q <= c; q++)
			ans += D[q][d] - D[q][b - 1];
		printf("%d\n", ans);
	}


}