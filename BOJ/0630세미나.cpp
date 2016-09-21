#include<iostream>
#include<queue>
using namespace std;
char map[105][105];
int visit[105][105];
int nvisit[105][105];
int N;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

bool chk(int x, int y)
{
	return x > 0 && x <= N&&y > 0 && y <= N;

}

int bfs(int x, int y)
{
	
	queue<pair<int, int>> q;

	q.push({ x,y });



	while (q.size())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (visit[y][x])
			continue;
		visit[y][x] = 1;
		for (int i= 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (chk(nx, ny))
			{
				if (map[y][x] == map[ny][nx]&&!visit[ny][nx])
				{
					q.push({ nx,ny });
				}
			}
		}
	}
	return 1;

}

int nbfs(int x, int y)
{

	queue<pair<int, int>> q;

	q.push({ x,y });
	while (q.size())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (nvisit[y][x])
			continue;
		nvisit[y][x] = 1;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (chk(nx, ny))
			{
				if (map[y][x] == 'B')
				{
					if (map[y][x] == map[ny][nx] && !nvisit[ny][nx])
					{
						q.push({ nx,ny });
					}
				}
				else
				{
					if ((map[ny][nx]=='R'||map[ny][nx]=='G') && !nvisit[ny][nx])
					{
						q.push({ nx,ny });
					}
				}
			}
		}
	}
	return 1;

}


int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%s", &map[i][1]);
	}

	int no = 0;	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!visit[i][j])
				no+=bfs(j, i);
		}
	}
	int nno=0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!nvisit[i][j])
				nno += nbfs(j, i);
		}
	}
	printf("%d %d", no, nno);
}