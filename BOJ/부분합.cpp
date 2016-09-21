#include<cstdio>
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int arr[10001];

	for (int i = 0; i < N;i++)
	scanf("%d", &arr[i]);

	int a = 0, b = 0;

	int sum= 0;
	int cnt = 0;
	while (a != N)
	{
		a++;
		sum += arr[a];
		
		if (sum > M)
		{
			sum -= arr[b];
			b++;
			
		}
	if (sum == M)
		cnt++;
	}

	printf("%d", cnt);


}