#include<cstring>
#include<cstdio>
#define MAX(a,b) a>b?a:b
int N, map[301],D[2][301];
int sol(int step, int n)
{
	if (n == N)return map[n];
	int &ret = D[step][n];
	if (ret != -1)return ret;
	ret = 0;

	if (n == 0)
	{
		ret = sol(0, 1);
		ret = MAX(ret, sol(0, 2));
	}
	else
	{
		if (step<1)
			ret = MAX(ret, sol(step + 1, n + 1)+map[n]);
		if(n+1<N)
			ret = MAX(ret, sol(0, n + 2)+map[n]);
	}
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &map[i]);
	memset(D, -1, sizeof(D));
	printf("%d", sol(0, 0));
}