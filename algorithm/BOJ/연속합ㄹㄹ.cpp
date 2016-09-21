#include<cstdio>
int in[100001];
int D[100001];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &in[i]);

	for (int i = 1; i <= N; i++)
	{
		D[i] = in[i];
		if (D[i - 1] + in[i] > D[i])
			D[i] = D[i - 1] + in[i];
	}
	int maxx = D[1];
	for (int i = 1; i <= N; i++)
	{
		if (D[i] > maxx)
			maxx = D[i];
	}
	printf("%d", maxx);

	return 0;

}