#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b))?a:b
int ga[111][111], se[111][111];
int D[111][111][222][2];
int M, N, L, G;

int main()
{
	int tc;
	scanf("%d", &tc);

	for (int itr = 0; itr < tc; itr++)
	{
		scanf("%d %d %d %d", &M, &N, &L, &G);

		for (int j = 1; j <= M; j++)
			for (int i = 1; i < N; i++)
				scanf("%d", &ga[j][i]);

		for (int j = 1; j < M; j++)
			for (int i = 1; i <= N; i++)
				scanf("%d", &se[j][i]);
		for (int j = 0; j <= M; j++)
			for (int i = 0; i <= N; i++)
				for (int k = 0; k <= i + j; k++)
					D[j][i][k][0] = D[j][i][k][1] = 987654321;
		D[1][1][0][0] = D[1][1][0][1] = 0;
		for (int j = 1; j <= M; j++)
			for (int i = 1; i <= N; i++)
			{
				for (int k = 0; k < i + j-1; k++)
				{
					if (i - 1 > 0)
						D[j][i][k][0] = D[j][i - 1][k][0] + ga[j][i - 1];
					if (k > 0)
					{
						if (i - 1 > 0)
							D[j][i][k][0] = min(D[j][i][k][0], D[j][i - 1][k - 1][1] + ga[j][i - 1]);
						if (j - 1 > 0)
							D[j][i][k][0] = min(D[j][i][k][0], D[j - 1][i][k - 1][1] + se[j - 1][i]);
					}
					if (k > 1)
					{
						if (j - 1 > 0)
							D[j][i][k][0] = min(D[j][i][k][0], D[j - 1][i][k - 2][0] + se[j - 1][i]);
					}

					if (j - 1 > 0)
						D[j][i][k][1] = D[j - 1][i][k][1] + se[j - 1][i];
					if (k > 0)
					{
						D[j][i][k][1] = min(D[j][i][k][1], D[j][i - 1][k - 1][0] + ga[j][i - 1]);
						D[j][i][k][1] = min(D[j][i][k][1], D[j - 1][i][k - 1][0] + se[j - 1][i]);
					}
					if (k > 1)
						D[j][i][k][1] = min(D[j][i][k][1], D[j][i - 1][k - 2][1] + ga[j][i - 1]);

				}
			}

		int minn = 987654321;
		for (int i = 0; i <N + M-2; i++)
		{
			if (G >= D[M][N][i][0])
			{
				if (minn > (M + N-2)*L + i)
					minn = (M + N-2)*L + i;
			}
			if (G >= D[M][N][i][1])
			{
				if (minn > (M + N - 2)*L + i)
					minn = (M + N - 2)*L + i;
			}
		}
		if (minn < 87654321)
			printf("%d\n", minn);
		else
			printf("-1\n");
	}
	return 0;
}