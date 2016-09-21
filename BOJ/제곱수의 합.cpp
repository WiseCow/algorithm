#include<cstdio>
int map[100001];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i <= N; i++)
		map[i] = i;

	for (int i = 2; i*i <= N; i++)
	{
		for (int j = i*i; j <= N; j++)
		{
			if (map[j] > map[j - i*i] + 1)
				map[j] = map[j - i*i] + 1;
		}
	}
	printf("%d", map[N]);
}