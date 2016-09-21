#include<iostream>
#include<queue>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int w, h;
int map[1001][1001];
struct Node {
	int x, y, cost;
};


bool chk(int x, int y)
{
	return x > 0 && x <= w&&y > 0 && y <= h;
}
int main()
{
	scanf("%d %d", &w, &h);
	queue<Node>q;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
			{
				q.push({ j,i,1 });
				map[i][j] = 0;
			}
		}
	int cc=0;
	

	while (q.size())
	{
		int x = q.front().x;
		int y = q.front().y;
		int cost = q.front().cost;
		q.pop();
		if (map[y][x] == 0 || map[y][x] > cost)
		{
			map[y][x] = cost;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (chk(nx, ny))
				{
					if (map[ny][nx] == 0 || map[ny][nx] > cost + 1)
					{
						q.push({ nx,ny,cost + 1 });
					}
				}
			}
		}
	}






	bool ck = 0;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
		{
			if (map[i][j] == 0)
				ck = 1;
			if (map[i][j] > cc)
				cc = map[i][j];
		}

	if (!ck)
		printf("%d", cc-1);
	else
		printf("-1");
}