#include<stdio.h>

int main()
{

	int a[100][100],b[100][100],c[100][100],N,M,L;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d ", &a[i][j]);

	scanf("%d %d", &M, &L);
	for (int i = 0; i < M; i++)
		for (int j = 0; j < L; j++)
			scanf("%d ", &b[i][j]);


	for (int i = 0; i < N; i++)
		for (int j = 0; j < L; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k<M; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < L; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}

}