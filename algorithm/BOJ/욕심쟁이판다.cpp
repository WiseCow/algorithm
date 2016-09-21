#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b))?a:b
int N, map[501][501], D[501][501];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
bool chk(int i, int j)
{
	return i > 0 && i <= N&&j > 0 && j <= N;
}
int sol(int i, int j)
{
	int &ret = D[i][j];
	if (ret != -1)return ret;
	ret = 1;
	int t = 0;
	for (int k = 0; k < 4; k++)
	{
		if (chk&&map[i][j] < map[i + dx[k]][j + dy[k]])
			t = max(t,sol(i + dx[k], j + dy[k]));
	}
	ret += t;
	return ret;

}
int main()
{
	scanf("%d", &N);
	memset(D, -1, sizeof(D));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);

	int mx = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			mx = max(mx, sol(i, j));

	printf("%d", mx);
}