#include<cstdio>
int arr[100][100];
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);


	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &arr[i][j]);

	int a;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &a);
			arr[i][j] += a;
		}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}

}