#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N, M;
int map[102][102];
int dist[101][102];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

struct Node {
	int x, y, cost;
};
bool chk(int x, int y)
{
	return x > 0 && x <= M&&y > 0 && y <= N;
}
int main()
{
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	memset(dist, 0x7f, sizeof(dist));

	queue<Node> q;
	q.push({ 1,1,0 });

	while (q.size())
	{
		int x = q.front().x;
		int y = q.front().y;
		int cost = q.front().cost;
		q.pop();

		if (dist[y][x] <= cost)
			continue;
		dist[y][x] = cost;
		for (int i = 0; i < 4;i++)
		{ 
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (chk(nx, ny))
			{
				if (map[ny][nx] == 0)
				{
					if (dist[ny][nx]>cost)
					{
						q.push({ nx,ny,cost });
					}
				}
				
				{
					if (dist[ny][nx]>cost+1)
					{
						q.push({ nx,ny,cost+1 });
					}
				}
			}
		}
	}
	printf("%d", dist[N][M]);



}
