#include<cstdio>
int N,sum,t,se;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &t);
		if (t)
			sum += ++se;
		else
			se = 0;
	}
	printf("%d", sum);
}