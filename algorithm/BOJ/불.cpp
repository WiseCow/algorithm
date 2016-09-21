#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int R, C;
char map[1010][1010];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int manmap[1010][1010];
int firemap[1010][1010];
struct Node {
	int x, y, cost;
};
bool chk(int y, int x)
{
	return y >= 0 && y < R&&x >= 0 && x < C;
}
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{
		scanf("%d %d", &C, &R);
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
				if (map[i][j] == '@')
					man.push({ j,i,1 });
				if (map[i][j] == '*')
					fire.push({ j, i, 1 });
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

					if (chk(ny, nx))
					{
						if (map[ny][nx] == '.'||map[ny][nx]=='@')
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
			if (manmap[y][x]>cost&&firemap[y][x] > cost)
			{
				manmap[y][x] = cost;

				for (int i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (chk(ny, nx))
					{
						if ((map[ny][nx] == '.') && firemap[ny][nx]>cost + 1)
							man.push({ nx, ny, cost + 1 });
					}
				}
			}
		}

		bool chk = 0;
		int N = 987654321;
		for (int i = 0; i < C; i++)
		{
			if (manmap[0][i] < 12345678)
			{
				chk = 1;
				if (manmap[0][i] < N)
					N = manmap[0][i];
			}
			if (manmap[R - 1][i] < 12345678) 
			{
				chk = 1;
				if (manmap[R-1][i] < N)
					N = manmap[R-1][i];
			}
		}
		for (int i = 0; i < R; i++)
		{
			if (manmap[i][0] < 12345567) {
				chk = 1;
				if (manmap[i][0] < N)
					N = manmap[i][0];
			}
			if (manmap[i][C-1] < 12345567) {
				chk = 1;
				if (manmap[i][C-1] < N)
					N = manmap[i][C-1];
			}
		}

		if (!chk)
		{
			printf("IMPOSSIBLE\n");
		}
		else
			printf("%d\n",N);


	}
}