#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node {
	int x, y, cost;
};
char map[50][51];
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int maxx, di[50][50],L,W;
bool en(int x, int y)
{
	bool chk = 1;
	if (x < 0 && x >= W&&y < 0 && y >= L)
		chk = 0;
	else
	{
		if (map[y][x] != 'L')
			chk = 0;
	}
	return chk;
}
int main()
{
	scanf("%d%d", &L, &W);
	for (int i = 0; i < L; i++)
		scanf("%s", &map[i]);

	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (map[i][j] == 'W')
				continue;
			int c = 0;
			for (int k = 0; k < 4; k++)
			{
				int nx = j + dx[k];
				int ny = i + dy[k];
				c += en(nx, ny);
			}
			if (c>=2)
				continue;
			memset(di, 0, sizeof(di));
			queue<node>q;
			q.push({ j,i,1 });
			while (q.size())
			{
				int x = q.front().x;
				int y = q.front().y;
				int cost = q.front().cost;
				q.pop();
				if (di[y][x] == 0 || di[y][x] > cost)
				{
					di[y][x] = cost;
					if (maxx < cost)
						maxx = cost;
					for (int i = 0; i < 4; i++)
					{
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (en(nx, ny) && (di[ny][nx] == 0 || di[ny][nx]>cost + 1))
						{
							q.push({ nx, ny, cost + 1 });
						}
					}
				}
			}
		}
	}
	printf("%d", maxx - 1);
}