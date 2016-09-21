#include<cstdio>
int main()
{
	int N, a = 1, b = 2, c;;
	scanf("%d", &N);
	for (int i = 3; i <= N; i++)
	{
		c = (a + b) % 15746;a = b;b = c;
	}
	printf("%d",c);
}