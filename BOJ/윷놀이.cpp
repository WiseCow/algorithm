#include<cstdio>
int main()
{
	for (int i = 0; i < 3; i++)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a + b + c + d == 4)
			printf("E\n");
		else
		{
			printf("%c\n", (3 - (a + b + c + d)+'A'));
		}
	}
}