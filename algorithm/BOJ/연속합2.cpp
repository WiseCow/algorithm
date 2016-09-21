#include<cstdio>
#include<cstring>
#define MAX(a,b) a>b?a:b
int N, map[100001],D[100001],mx;
int sol(int n)
{
	if (n == 1)return map[n];
	int &ret = D[n];
	if (ret != -987654321)return ret;
	ret = map[n];

	ret = MAX(ret, sol(n - 1) + ret);
	mx = MAX(mx, ret);
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)scanf("%d", &map[i]);
	for (int i = 0; i <= N; i++)D[i] = -987654321;
	mx = map[1];
	sol(N);
	printf("%d", mx);
}