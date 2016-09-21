#include<iostream>
#include<queue>
int N;
char map[101][101];
int nodist[101][101], dist[101][101];
bool chk(int x, int y){	return x >= 0 && x < N&&y >= 0&&y < N;}
int no, yes;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

using namespace std;

void bfs(int y, int x, char word)
{
	if (nodist[y][x]==0)
	{
		no++;
		queue<pair<int, int>>q;
		q.push({ x,y });

		while (q.size())
		{
			auto au = q.front();
			q.pop();

			x = au.first;
			y = au.second;

			if (nodist[y][x]==0)
			{
				nodist[y][x] = no;

				for (int i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (chk(nx, ny))
					{
						if (map[ny][nx] == word&&nodist[ny][nx]==0)
							q.push({ nx,ny });
					}
				}
			}
		}
	}
}
void ybfs(int y, int x, char word)
{
	if (dist[y][x]==0)
	{
		yes++;
		queue<pair<int, int>>q;
		q.push({ x,y });

		while (q.size())
		{
			auto au = q.front();
			q.pop();

			x = au.first;
			y = au.second;

			if (dist[y][x]==0)
			{
				dist[y][x] = yes;

				for (int i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (chk(nx, ny))
					{
						if (word == 'R' || word == 'G')
						{
							if((map[ny][nx]=='R'||map[ny][nx]=='G')&&dist[ny][nx] == 0)
								q.push({ nx,ny });
						}
						else
						{
							if (map[ny][nx] == word&&dist[ny][nx] == 0)
								q.push({ nx,ny });
						}
					}
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", &map[i]);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			bfs(i, j, map[i][j]);
	printf("%d ", no);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ybfs(i, j, map[i][j]);

	printf("%d\n", yes);
}