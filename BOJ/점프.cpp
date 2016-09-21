#include<cstdio>
long long D[101][101];
char map[101][101];
int N;
long long sol(int x, int y)
{
	if (x == N&&y == N)
		return 1;
	long long &ret = D[x][y];
	if (ret != -1)return ret;
	int d = map[x][y];
	ret = 0;
	if (x + d <= N)ret += sol(x + d, y);
	if (y + d <= N)ret += sol(x, y + d);
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
			D[i][j] = -1;
		}
	printf("%lld", sol(1,1));
}