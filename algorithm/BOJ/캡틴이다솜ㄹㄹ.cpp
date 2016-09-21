#include<cstdio>
#define min(a,b) ((a)<(b))?a:b
int D[300001] = { 0 };
int main()
{
	int a[130] = { 0 };
	int b[130] = { 0 };
	int N;
	scanf("%d", &N);
	for (int i = 1; i < 130; i++)
		a[i] = i + a[i - 1];
	for (int i = 1; i < 130; i++)
		b[i] = a[i] + b[i - 1];

	for (int i = 1; i <= N; i++)
	{
		D[i] = i;

		for (int j = 1; b[j] <= i; j++)
			D[i] = min(D[i], D[i-b[j]] + 1);
	}
	printf("%d", D[N]);
}
