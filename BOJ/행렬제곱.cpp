#include<stdio.h>
int main()
{

	int a[100][100], c[2][100][100], N;
	long long M;

	scanf("%d %lld", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d ", &a[i][j]);


	for (int l = 1; l <= M; l++)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
					c[l%2][i][j] = 0;
				for (int k = 0; k < N; k++) {
					if(l==1)
						c[l%2][i][j] += a[i][k] * a[k][j];
					else
						c[l % 2][i][j] += c[(l + 1) % 2][i][k] * a[k][j];
					c[l % 2][i][j] %= 1000;
				}
			}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", c[(M+1)%2][i][j]);
		printf("\n");
	}

}