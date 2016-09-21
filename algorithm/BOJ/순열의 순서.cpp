#include<cstdio>

long long pac[21];
int main()
{
	int N, K;
	scanf("%d", &N);
	pac[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		pac[i] = pac[i - 1] * i;
	}

	scanf("%d", &K);
	if (K == 1)
	{
		long long  t;
		scanf("%lld", &t);
		bool visit[21] = { 0 };
		t--;
		for (int i = 1; i <= N; i++)
		{
			int j = 0;
			for (;;)
			{
				j++;
				
				if (visit[j])continue;
				if (t < pac[N - i])
					break;
				else
				{
					t -= pac[N - i];
					if (i==N&&t == 0)
						break;
				}
			}
			printf("%d ", j);
			visit[j] = 1;
		}
	}
	else
	{
		long long int res=0;
		int t;
		bool visit[21] = { 0 };
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &t);
			for (int j = 1; j < t; j++)
			{
				if (!visit[j])
					res += pac[N - i];
			}
			visit[t] = 1;
		}
		printf("%lld\n", res+1);
	}
	return 0;
}