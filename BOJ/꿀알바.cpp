#include<cstdio>
#define max(a,b) a>b?a:b
int n, m;
int Ti[100001];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int t;
		scanf("%d", &t);
		Ti[i] = Ti[i - 1] + t;
	}
	long long maxxx = 0;
	for (int i = 0; i <= n - m; i++)

		maxxx = max(maxxx, Ti[i + m] - Ti[i]);
	printf("%lld\n", maxxx);
}