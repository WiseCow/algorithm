#include<cstdio>
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<(b))?(a):(b)
int main()
{
	int N;
	scanf("%d", &N);
	int maxx,minn, aa, ab, ac,ia, ib, ic;
	scanf("%d %d %d", &aa, &ab, &ac);
	ia = aa; ib = ab; ic = ac;
	for (int i =1; i < N; i++)
	{
		int a, b, c,ta,tb,tc;
		scanf("%d %d %d", &a,&b,&c);
		ta = a; tb = b; tc = c;
		a += max(aa, ab);
		ta += min(ia, ib);
		b += max(aa, max(ab, ac));
		tb += min(ia, min(ib, ic));
		c += max(ab, ac);
		tc += min(ib, ic);
		aa = a; ab = b; ac = c;
		ia = ta; ib = tb; ic = tc;
	}
	maxx = max(aa, max(ab, ac));
	minn = min(ia, min(ib, ic));
	printf("%d %d", maxx,minn);
}