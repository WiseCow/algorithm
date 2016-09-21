#include<cstdio>
#include<cstring>
int tc,N, DP[12];
int sol(int i)
{
	if (i == 1)return 1;
	if (i == 2)return 2;
	if (i == 3)return 4;
	int &ret = DP[i];
	if (ret != -1)return ret;
	return ret = sol(i - 1) + sol(i - 2) + sol(i - 3);
}
int main()
{
	scanf("%d", &tc);
	memset(DP, -1, sizeof(DP));
	for (int itr = 0; itr < tc; itr++)
	{
		scanf("%d", &N);
		printf("%d\n",sol(N));
	}
}