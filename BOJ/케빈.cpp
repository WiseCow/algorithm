#include<iostream>
#define INF 987654321
using namespace std;
int main()
{
	int arr[101][101] = { 0 };
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1;j  <= N; j++)
		{
			if (i == j)continue;
			arr[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				if (i != j&&arr[i][j]>arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}

	int max = 9999999,num;
	for (int i = 1; i <= N; i++)
	{
		int k = 0;
		for (int j = 1; j <= N; j++)
		{
			if (i == j)continue;
			
				k += arr[i][j];
		}
		if (k < max)
		{
			max = k;
			num = i;
		}
	}
	printf("%d", num);
}