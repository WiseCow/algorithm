#include<cstdio>
#define MAX(a,b) a>b?a:b
int main()
{
	int N;
	scanf("%d", &N);
	int arr[1001], D[1001] = { 0 };
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	D[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		D[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[j] > arr[i])
			{
				D[i] = MAX(D[i], D[j] + 1);
			}
		}
	}

	int k = 1;
	for (int i = 1; i <= N; i++)k = MAX(k, D[i]);
	printf("%d", k);
}