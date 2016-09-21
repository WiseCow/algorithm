#include<cstdio>
#include<cstring>
int N, M, K, D[11][221][221];
int sol(int n, int m, int use)
{
	if (n == 0)
	{
		if (m == 0)
			return 1;
		return 0;
	}
	int &ret = D[n][m][use];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = use; i <= m; i++)
		ret += sol(n - 1, m - i, i);
	return ret;
}
void print(int n,int m, int use, int k)
{
	if (n == 0)return;
	int cnt, find=k;

	for (int i = use; i <= m; i++)
	{
		cnt = sol(n - 1, m - i, i);
		if (cnt > find)
		{
			printf("%d ", i);
			print(n - 1, m - i, i, find);
			break;
		}
		find -= cnt;
	}
}
int main()
{
	scanf("%d%d%d", &N, &M, &K);
	memset(D, -1, sizeof(D));
	sol(N, M, 1);
	print(N, M, 1, K - 1);
}