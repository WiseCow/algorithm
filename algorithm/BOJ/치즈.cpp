#include<iostream>
#include<queue>
using namespace std;
int w, h, map[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
bool chk(int y, int x)
{
	return x > 0 && x <= w&&y > 0 && y <= h;
}
int main()
{
	scanf("%d %d", &h, &w);

	int prev = 0;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				prev++;
		}
	}


	int nowc = 0;
	while (1)
	{
		
		int cnt = 0;
		queue<pair<int, int>>q;
		q.push({ 1,1 });
		int visit[101][101] = { 0 };
		visit[1][1] = 1;
		while (q.size())
		{
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (chk(ny, nx)&&!visit[ny][nx])
				{
					visit[ny][nx] = 1;
					if (map[ny][nx] == 1)
					{
						map[ny][nx] = 0;
						cnt++;
					}
					else
						q.push({ nx,ny });
				}
			}
		}
		if (cnt == 0)
		{
			printf("%d\n%d", nowc, prev);
			break;
		}
		nowc++;
		prev = cnt;
	}
}