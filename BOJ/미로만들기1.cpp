#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int  n;
int map[51][51];
int mapcost[51][51];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct Node { int x, y, cost; };
bool chk(int x, int y)
{
	return x > 0 && x <= n&&y >0 && y <=n;
}

int bfs()
{
	queue<Node> q;

	q.push({ 1,1,0 });
	while (q.size())
	{
		int x, y, cost;
		x = q.front().x;
		y = q.front().y;
		cost = q.front().cost;
		q.pop();

		
		if (mapcost[y][x] > cost)
		{
			mapcost[y][x] = cost;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (chk(nx, ny))
				{
					if (!map[ny][nx] && mapcost[ny][nx]>cost + 1)
					{
						q.push({ nx,ny,cost + 1 });
					}
					if (map[ny][nx] && mapcost[ny][nx] > cost)
					{
						q.push({ nx,ny,cost });
					}
				}
			}
		}
	}



	return mapcost[n][n];
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%1d", &map[i][j]);
	memset(mapcost, 0x7f, sizeof(mapcost));
	printf("%d", bfs());
}