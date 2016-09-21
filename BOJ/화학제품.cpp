#include<iostream>
#define MIN(a,b) ((a)<(b))?(a):(b)
#define MAX(a,b) ((a)>(b))?(a):(b)
using namespace std;
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		int a, b, c, ab, bc, ca, r[3] = { 0 };
		long long sum;
		scanf("%d %d %d", &a, &b, &c);
		scanf("%d %d %d", &ab, &bc, &ca);
		sum = 0;
		r[0] = MIN(a, b);
		r[1] = MIN(b, c);
		r[2] = MIN(c, a);
		for (int i = 0; i <=r[0]; i++)
		{
			for (int j = 0; j <= b - i && j <= c; j++)
			{
				int k = MIN(a - i, c - j);
				sum = MAX(sum, ab*i + bc*j + ca*k);
			}
		}
		printf("%lld\n",sum);
	}
}
