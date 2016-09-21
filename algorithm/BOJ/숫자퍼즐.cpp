#include<cstdio>
#include<cstring>
bool map[9][9];
int sx, sy, fx, fy, M, N;
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int rec[70][2];
bool f = 0;
bool chk(int x, int y)
{
	return x > 0 && x <= M&&y > 0 && y <= N;
}
bool dfs(int x, int y, int n)
{

	map[x][y] = 1;
	rec[n][0] = x;
	rec[n][1] = y;
	if (x == fx&&y == fy)
	{
		if (n == M*N)
		{
			printf("1\n");
			for (int i = 1; i <= M*N; i++)
				printf("%d %d\n", rec[i][0], rec[i][1]);
			f = 1;
			return 1;
		}
		else
		{
			map[x][y] = 0;
			return 0;
		}
	}
	for (int i = 0; i < 4&&f==0; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (chk(nx, ny) && !map[nx][ny] && dfs(nx, ny, n + 1))
		{
			break;
		}
	}
	map[x][y] = 0;
	return 0;
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{
		memset(map, 0, sizeof(map));
		scanf("%d%d", &M, &N);
		scanf("%d%d", &sx, &sy);
		scanf("%d%d", &fx, &fy);
		f = 0;
		dfs(sx, sy, 1);
		if(!f)
			printf("-1\n");
	}

}