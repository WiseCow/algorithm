#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int M, N, sx, sy, sd, fx, fy, fd;
struct Data { int x, y, dist, cost; };
int dx[5] = {0,1,-1,0,0};
int dy[5] = {0,0,0,1,-1};
bool chk(int x, int y)
{
	return x > 0 && x <= N&&y > 0 && y <= M;
}
int main()
{
	scanf("%d %d", &M, &N);
	int map[101][101];
	for (int i = 1; i <= M; i++)for (int j = 1; j <= N; j++)scanf("%d", &map[i][j]);
	scanf("%d %d %d", &sy, &sx, &sd);
	scanf("%d %d %d", &fy, &fx, &fd);

	int dist[5][101][101];
	memset(dist, 0x7f, sizeof(dist));

	queue<Data> q;
	q.push({ sx,sy,sd,0 });

	while(q.size())
	{
		int x = q.front().x;
		int y = q.front().y;
		int di = q.front().dist;
		int co = q.front().cost;
		q.pop();

		if (dist[di][y][x] <= co)
			continue;
		dist[di][y][x] = co;
		if (di == fd&&x == fx&&y == fy)
			break;

		int nd;
		if (di == 1)
		{
			if (dist[3][y][x] > co + 1)
				q.push({ x,y,3,co + 1 });
			if (dist[4][y][x] > co + 1)
				q.push({ x,y,4,co + 1 });
		}
		else if (di == 2)
		{
			if (dist[3][y][x] > co + 1)
				q.push({ x,y,3,co + 1 });
			if (dist[4][y][x] > co + 1)
				q.push({ x,y,4,co + 1 });
		}
		else if (di == 3)
		{
			if (dist[1][y][x] > co + 1)
				q.push({ x,y,1,co + 1 });
			if (dist[2][y][x] > co + 1)
				q.push({ x,y,2,co + 1 });
		}
		else
		{
	
				if (dist[1][y][x] > co + 1)
					q.push({ x,y,1,co + 1 });
				if (dist[2][y][x] > co + 1)
					q.push({ x,y,2,co + 1 });
			

		}


		for (int i = 1; i < 4; i++)
		{
			int nx = x + dx[di] * i;
			int ny = y + dy[di] * i;

			if (chk(nx, ny))
			{
				if (map[ny][nx] == 1)
					break;
				else
				{
					if (dist[di][ny][nx]>co + 1)
						q.push({nx, ny, di, co + 1});
				}
			}
		}
	}
	printf("%d", dist[fd][fy][fx]);


}