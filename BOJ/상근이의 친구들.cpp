#include<cstdio>
int a, b;
int main()
{
	while (1)
	{
		scanf("%d%d", &a, &b);
		if (a + b == 0)
			return 0;
		printf("%d\n", a + b);
	}
}