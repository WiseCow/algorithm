#include<iostream>
#include<queue>
using namespace std;
int n, m;
int map[101][101];
int visit[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
bool chk(int x, int y)
{
	return x > 0 && x <= m&&y > 0 && y <=n;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &map[i][j]);

	queue<pair<int, int>> q;


	q.push({ 1,1 });
	visit[1][1] = 1;

	while (q.size())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (chk(nx, ny))
			{
				if (map[ny][nx]==1&&(visit[ny][nx] == 0 || visit[ny][nx]>visit[y][x] + 1))
				{
					visit[ny][nx] = visit[y][x] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}

	printf("%d", visit[n][m]);
}