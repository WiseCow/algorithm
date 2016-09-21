#include<iostream>
#include<queue>
using namespace std;

int N;
int map[30][30];
bool visit[30][30];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
priority_queue<int> q;
bool chk(int x, int y)
{
	return x > 0 && x <= N&&y > 0 && y <= N;
}
void bfs(int x, int y)
{
	if (!visit[y][x])
	{
		queue<pair<int, int>> qq;
		int res = 0;
		qq.push({ x,y });

		while (qq.size())
		{
			auto au = qq.front();
			qq.pop();
			x = au.first;
			y = au.second;

			if (!visit[y][x])
			{
				visit[y][x] = 1;
				res++;
				for (int i = 0; i < 4; i++)
				{
					int nx = au.first + dx[i];
					int ny = au.second + dy[i];
					if (chk(nx,ny))
					{
						if (map[ny][nx] == 1&&visit[ny][nx]==0)
							qq.push({ nx,ny });
					}
				}
			}
		}
		q.push(-res);
	}
}
int main()
{
	scanf("%d", &N);



	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%1d", &map[i][j]);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j]==1)
				bfs(j, i);
		}
	}

	printf("%d\n", q.size());


	while (q.size())
	{
		printf("%d\n", -q.top());
		q.pop();
	}

	return 0;
}