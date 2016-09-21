#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int R, C;
char map[55][55];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int manmap[55][55];
int firemap[55][55];
struct Node {
	int x, y, cost;
};
bool chk(int y, int x)
{
	return y >= 0 && y < R&&x >= 0 && x < C;
}
int main()
{
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)
		scanf("%s", &map[i]);

	queue<Node> fire;
	queue<Node> man;

	int xd = 0, yd = 0;
	memset(firemap, 0x7f, sizeof(firemap));
	memset(manmap, 0x7f, sizeof(manmap));
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 'S')
				man.push({ j,i,1 });
			if (map[i][j] == '*')
				fire.push({ j, i, 1 });
			if (map[i][j] == 'D')
			{
				xd = j;
				yd = i;
			}
		}
	}
	while (fire.size())
	{
		int x = fire.front().x;
		int y = fire.front().y;
		int cost = fire.front().cost;
		fire.pop();
		if (firemap[y][x]>cost)
		{
			firemap[y][x] = cost;

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if (chk(ny,nx))
				{
					if (map[ny][nx] == '.')
						fire.push({ nx, ny, cost + 1 });
				}
			}
		}
	}

	while (man.size())
	{
		int x = man.front().x;
		int y = man.front().y;
		int cost = man.front().cost;
		man.pop();
		if (manmap[y][x]>cost&&firemap[y][x]>cost)
		{
			manmap[y][x] = cost;

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (chk(ny, nx))
				{
					if ((map[ny][nx] == '.'|| map[ny][nx] == 'D')&&firemap[ny][nx]>cost+1)
						man.push({ nx, ny, cost + 1 });
				}
			}
		}
	}

	if (manmap[yd][xd] > 12345678)
	{
		printf("KAKTUS");
	}
	else
		printf("%d", manmap[yd][xd]-1);



}