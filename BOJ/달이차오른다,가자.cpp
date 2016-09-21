#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int Y, X, sx, sy;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
char map[52][52];
int dist[1<<6][50][50];
struct Node
{
	int x, y, cost, bit;
};
queue<Node> qu;
bool chk(int x, int y)
{
	return x >= 0 && x < X&& y >= 0 && y < Y;
}
int main()
{
	memset(dist, 0x3f, sizeof(dist));
	scanf("%d %d", &Y, &X);
	for (int i = 0; i < Y; i++)
	{
		scanf("%s", &map[i]);
		for (int j = 0; j < X; j++)
		{
			if (map[i][j] == '0')
			{
				sx = j;	sy = i;
			}
		}
	}
	qu.push({ sx,sy,0,0 });

	bool cc = 0;
	int res = 0;
	while (qu.size())
	{
		int x = qu.front().x;
		int y = qu.front().y;
		int cost = qu.front().cost;
		int bit = qu.front().bit;
		qu.pop();
		if (dist[bit][y][x] < cost)
			continue;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nbit = bit;
			if (!chk(nx, ny))
				continue;
			if (map[ny][nx] >= 'a'&&map[ny][nx] <= 'f')
			{
				nbit = bit | (1 << (map[ny][nx] - 'a'));
			}
			if (map[ny][nx] >= 'A'&&map[ny][nx] <= 'F')
			{
				if (!(bit& (1 << (map[ny][nx] - 'A'))))
					continue;
			}
			if (map[ny][nx] == '#')
				continue;
			if (map[ny][nx] == '1')
			{
				cc = 1;
				res = cost + 1;
				break;
			}
			if (dist[bit][ny][nx] > cost + 1)
			{
				dist[bit][ny][nx] = cost + 1;
				qu.push({ nx, ny, cost + 1, nbit });
			}
		}
		if (cc)
			break;
	}
	if (cc)
		printf("%d", res);
	else
		printf("-1");
}


