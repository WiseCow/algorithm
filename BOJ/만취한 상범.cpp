#include<cstdio>
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{
		int map[101] = { 0 };
		int n;
		scanf("%d", &n);

		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j*i <= n; j++)
			{
				if (map[i*j] == 0)
					map[i*j] = 1;
				else
					map[i*j] = 0;
			}
		}

		int k = 0;
		for (int i = 1; i <= n; i++)
			if (map[i] == 0)
				k++;

		printf("%d\n", k);
	}
}