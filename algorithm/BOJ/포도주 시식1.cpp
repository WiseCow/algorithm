#include<cstdio>
#include<cstring>
#define MAX(a,b) a>b?a:b
int n, map[10001],DP[10001][3];

int sol(int i, int sel)
{
	if (i > n)
		return 0;
	if (sel == 3)
		return 0;

	int &ret = DP[i][sel];
	if (ret != -1)return ret;
	ret = 0;


	if (i == 0)
	{
		ret = sol(1, 0);
	}
	else
	{

		ret = sol(i + 1, 0);
		if (sel != 2)
			ret = MAX(ret, sol(i + 1, sel + 1) + map[i]);
	}
	return ret;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &map[i]);
	memset(DP, -1, sizeof(DP));
	printf("%d", sol(0, 0));
}