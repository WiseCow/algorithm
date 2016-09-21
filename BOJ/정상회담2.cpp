#include<cstdio>
#define mod 987654321
long long d[10002];
int main()
{
	long long n;
	scanf("%lld", &n);
	d[0] = 1;
	d[1] = 0;
	d[2] = 1;
	d[3] = 0;
	d[4] = 2;
	for (int i = 6; i <= n; i += 2)
		for (int j = 2; j <= i; j += 2)
			d[i] += d[i - j] * d[j - 2],
			d[i] %= mod;
	printf("%lld\n", d[n] %= mod);
	return 0;
}