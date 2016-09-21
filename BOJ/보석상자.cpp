#include<cstdio>
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
int N, M,ma=987654321;
int jewe[300001];
bool cut(int cutsize)
{
	int k = 0;
	int mx = 0;
	for (int i = 0; i < M; i++)
	{
		int t = jewe[i] / cutsize;
		k += t;
	}
	if (k>=N)
	{
		return true;
	}
	else
		return false;

}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &jewe[i]);
		ma = MIN(ma, jewe[i]);
	}
	int l = 1, r = ma,mid;
	int oo = 0;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (cut(mid))
		{
			l = mid+1;
			oo = MAX(oo, mid);
		}
		else
			r = mid-1;
	}
	ma = 0;
	for (int i = 0; i < M; i++)
	{
		int t = jewe[i] / oo;
		ma = MAX(ma, oo+(jewe[i] % oo) % t);
	}
	printf("%d", ma);
}