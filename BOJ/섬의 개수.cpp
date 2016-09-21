#include<iostream>
#include<queue>
using namespace std;
int w, h,map[60][60],cnt;
int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
bool chk(int y, int x)
{
	return x > 0 && x <= w&&y > 0 && y <= h;
}
void bfs(int y, int x, int visit[60][60])
{

	cnt++;
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (q.size())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (visit[y][x])
			continue;
		visit[y][x] = 1;

		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (chk(ny, nx) && !visit[ny][nx] && map[ny][nx])
				q.push({ nx, ny });
		}
	}

}
int main()
{
	while (1)
	{
		scanf("%d %d",&w,&h);
		if (h == 0 && w == 0)
			break;
		cnt = 0;
		int visit[60][60]={0};
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				scanf("%d", &map[i][j]);

			}
		}
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				if (!visit[i][j] && map[i][j])
				{
					bfs(i, j, visit);
				}
			}
		}

		printf("%d\n", cnt);
	}
}