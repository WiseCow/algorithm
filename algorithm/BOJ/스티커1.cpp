#include<cstdio>
#include<cstring>
#define MAX(a,b) a>b?a:b
int map[100001][2],DP[100001][2],tc,N;
int sol(int i,int position)
{
	if (i > N)
		return 0;
	int &ret = DP[i][position];
	if (ret != -1)return ret;
	ret = 0;

	if (i == 0)
	{
		ret = sol(1, 0);
		ret = MAX(ret,sol(1, 1));
	}
	else
	{
		if (position == 0)
		{
			ret = map[i][0] + sol(i + 1, 1);
			ret = MAX(ret, map[i][0] + sol(i + 2, 0));
			ret = MAX(ret, sol(i + 1, 0));
		}
		else
		{
			ret = map[i][1] + sol(i + 1, 0);
			ret = MAX(ret, map[i][1] + sol(i + 2, 1));
			ret = MAX(ret, sol(i + 1, 1));
		}
	}
	return ret;




}
int main()
{
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)scanf("%d", &map[i][0]);
		for (int i = 1; i <= N; i++)scanf("%d", &map[i][1]);
		memset(DP, -1, sizeof(DP));
		printf("%d\n", sol(0,0));
	}
}