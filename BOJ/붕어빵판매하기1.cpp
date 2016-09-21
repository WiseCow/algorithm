#include<cstdio>
#include<cstring>
#define MAX(a,b) a>b?a:b
int N, map[1001], DP[1001][1001];
int sol(int now, int na)
{
	if (na == 0)return 0;

	int &ret = DP[now][na];
	if (ret != -1)return ret;
	ret = 0;

	for (int i = 1; i <= N; i++)
	{
		if (na - i >= 0)
			ret = MAX(ret, sol(i, na - i)+map[i]);
	}
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)scanf("%d", &map[i]);
	memset(DP, -1, sizeof(DP));
	printf("%d",sol(0,N));
}