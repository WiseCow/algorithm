#include<cstdio>
int main()
{
	int arr[201],D[201];
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	D[1] = arr[1];
	int mx = 1;
	for (int i = 2; i <= N; i++)
	{
		int j;
		for ( j = mx; j > 0; j--)
		{
			if (D[j] < arr[i])
				break;
		}
		j++;
		D[j] = arr[i];
		if (mx < j)
			mx = j;
	}
	printf("%d", N - mx);
}
