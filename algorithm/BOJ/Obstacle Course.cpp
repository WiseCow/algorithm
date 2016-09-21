#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N,map[130][130],dist[130][130],tc;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
bool chk(int x, int y)
{
	return x >= 0 && x < N&&y >= 0 && y < N;
}
int main()
{
	while (1)
	{
		tc++;
		scanf("%d", &N);
		if (N == 0)
			break;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &map[i][j]);
		memset(dist, 0x3f, sizeof(dist));

		dist[0][0] = map[0][0];

		priority_queue <pair<int, pair<int, int>>>pq;
		pq.push({ -(dist[0][0] + map[1][0]),{1,0} });
		pq.push({ -(dist[0][0] + map[0][1]),{ 0,1 } });

		while (pq.size())
		{
			int cost = -pq.top().first;
			int y = pq.top().second.first;
			int x = pq.top().second.second;
			pq.pop();
			if (dist[y][x] <= cost)
				continue;
			dist[y][x] = cost;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (chk(nx, ny) && dist[ny][nx]>cost + map[ny][nx])
				{
					pq.push({ -(cost + map[ny][nx]),{ny,nx}});
				}
			}
		}
		printf("Problem %d: %d\n", tc, dist[N - 1][N - 1]);


	}
}