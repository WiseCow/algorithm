#include<cstdio>
#define MAX(a,b) a>b?a:b
int main()
{
	int N;
	scanf("%d", &N);
	int arr[1001], U[1001], D[1001];
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
		D[i] = U[i] = 1;

	}

	for (int i = N-1; i >= 1; i--)
	{
		for (int j = N; j >i; j--)
		{
			if (arr[j] < arr[i])
			{
				D[i] = MAX(D[i], D[j] + 1);
			}
		}
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				U[i] = MAX(U[i], U[j] + 1);
			}
		}
	}


	int k = 1;
	for (int i = 1; i <= N; i++)k = MAX(k, D[i]+U[i]);
	printf("%d", k-1);
}