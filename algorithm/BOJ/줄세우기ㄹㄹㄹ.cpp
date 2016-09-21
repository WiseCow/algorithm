#include<cstdio>
int arr[201], D[201];
int main()
{
	int N;
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	int end = 1;
	D[1] = arr[1];
	for (int i = 2; i <= N; i++)
	{
		int j;
		for (j = end; j > 0; j--)
		{
			if (D[j] < arr[i])
				break;
		}
		j++;
		D[j] = arr[i];
		if (j > end)
			end = j;
	}

	printf("%d", N - end);

}