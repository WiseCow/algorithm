#include<cstdio>
#include<cstring>
#define MAX(a,b) a>b?a:b
int N, M, map[1001][1001], D[1001][1001];
int sol(int y, int x)
{
	if (y == N&&x == M)return map[y][x];
	int &ret = D[y][x];
	if (ret != -1)return ret;
	ret = 0;
	if (y < N&&x < M)
		ret = MAX(ret, sol(y + 1, x + 1) + map[y][x]);
	if (y < N)
		ret = MAX(ret, sol(y+1, x ) + map[y][x]);
	if (x < M)
		ret = MAX(ret, sol(y, x+1) + map[y][x]);
	return ret;
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++)scanf("%d", &map[i][j]);
	memset(D, -1, sizeof(D));
	printf("%d", sol(1, 1));
}