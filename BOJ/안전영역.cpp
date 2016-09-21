#include<iostream>
#include<queue>
using namespace std;
int map[101][101];
int N;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

bool chk(int x, int y)
{
	return x > 0 && x <= N&&y > 0 && y <= N;
}

int bfs(int now)
{
		queue<pair<int,int>> q;
		int visit[101][101] = { 0 };
		int res = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (map[i][j] > now&&!visit[i][j])
				{
					q.push({ i,j });
					res++;
					while (q.size())
					{
						int y = q.front().first;
						int x = q.front().second;
						q.pop();
						if (visit[y][x])
							continue;
						visit[y][x] = 1;

						for (int i = 0; i < 4; i++)
						{
							int nx = x + dx[i];
							int ny = y + dy[i];
							if (chk(nx, ny) && map[ny][nx]>now&&!visit[ny][nx])
							{
								q.push({ ny,nx });
							}
						}
					}
				}
			}
		}
		return res;
}
int main() 
{
	int milv = 987654321, mxlv = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
			if (milv > map[i][j])
				milv = map[i][j];
			if (mxlv < map[i][j])
				mxlv = map[i][j];
		}
	int k = 0;
	for (int i = milv-1; i <= mxlv; i++)
	{
		int a = bfs(i);
		if (k < a)
			k = a;
	}
	printf("%d", k);
}