#include<cstdio>
bool prim[100001] = { 0 };
int main()
{
	int tc;
	scanf("%d", &tc);
	prim[0] = prim[1] = 1;
	for (int i = 2; i <= 100000; i++)
	{
		if (!prim[i])
		{
			for (int j = 2; j*i <= 100000; j++)
			{
				prim[i*j] = 1;
			}
		}
	}
	for (int itr = 0; itr < tc; itr++)
	{
		int a;
		scanf("%d", &a);
		int c[100001] = { 0 }, m;
		for (int i = 2; a != 1; i++)
		{
			if (prim[i])
				continue;
			if (a%i == 0)
			{
				c[i]++;
				a /= i;
				m = i;
				i--;
			}
		}
		for (int i = 2; i <= m; i++)
		{
			if (c[i])
			{
				printf("%d %d\n", i, c[i]);
			}
		}


	}
}