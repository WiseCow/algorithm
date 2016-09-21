#include<cstdio>
int N, S,in[21],cnt;
int main()
{
	scanf("%d %d", &N, &S);
	for (int i = 1; i <= N; i++)
		scanf("%d", &in[i]);

	for (int i = 1; i < (1 << N); i++)
	{
		int sum=0;
		int k=1;
		for (int j = 1; j <= i; j<<=1,k++)
		{
			if ((i&j) == j)
				sum += in[k];
		}
		if (sum == S)
			cnt++;
	}
	printf("%d", cnt);
}