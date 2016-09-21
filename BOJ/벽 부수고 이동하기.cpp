#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N, M;
int map[1001][1001];
int dist[2][1001][1001];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
struct Node {
	int x, y,cost,dist;
};
 bool chk(int x, int y)
{
	return x > 0 && x <= M&&y > 0 && y <= N;
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	memset(dist, 0x7f, sizeof(dist));
	queue<Node>q;
	q.push({ 1,1,0,1 });

	while (q.size())
	{
		int x = q.front().x;
		int y = q.front().y;
		int co = q.front().cost;
		int di = q.front().dist;
		q.pop();
		if (dist[co][y][x] <= di)
			continue;
		dist[co][y][x] = di;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (chk(nx, ny))
			{
				if (map[ny][nx] == 0)
				{
					if (dist[co][ny][nx]>di + 1)
						q.push({ nx,ny,co,di + 1 });
				}
				else
				{
					if (co == 0 && dist[co + 1][ny][nx]> di + 1)
						q.push({ nx,ny,co + 1,di + 1 });
				}
			}
		}
	}
	if (dist[0][N][M] < 12345678&& dist[1][N][M]<12345678)
	{
		if (dist[0][N][M] < dist[1][N][M])
			printf("%d", dist[0][N][M]);
		else
			printf("%d", dist[1][N][M]);
	}
	else if (dist[0][N][M] < 12345678)
	{
		printf("%d", dist[0][N][M]);
	}
	else if (dist[1][N][M] < 12345678)
	{
		printf("%d", dist[1][N][M]);
	}
	else
		printf("-1");
}
















//#include<iostream>
//#include<queue>
//#include<cstring>
//using namespace std;
//int map[1001][1001];
//int dist[1001][1001];
//int cost[1001][1001];
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { 1,0,-1,0 };
//int N, M;
//struct Node {
//	int x, y, cost,dist;
//};
//bool chk(int x, int y)
//{
//	return x > 0 && x <= M&&y > 0 && y <= N;
//}
//int main()
//{
//	scanf("%d %d", &N, &M);
//	for (int i = 1; i <= N; i++)
//		for (int j = 1; j <= M; j++)
//		{
//			scanf("%1d", &map[i][j]);
//		}
//	memset(dist, 0x7f, sizeof(dist));
//	memset(cost, 0x7f, sizeof(cost));
//
//	queue<Node> q;
//	q.push({ 1,1,1,1 });
//
//	while (q.size())
//	{
//		int x = q.front().x;
//		int y = q.front().y;
//		int co = q.front().cost;
//		int di = q.front().dist;
//		q.pop();
//		if (co == 0)
//		{
//			if (dist[y][x] < di)
//				continue;
//		}
//		if(dist[y][x]>di)
//			dist[y][x] = di;
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			if (chk(nx, ny))
//			{
//				if (map[ny][nx] == 1)
//				{
//					if(co>0&&dist[ny][nx]>di+1)
//						q.push({ nx,ny ,co - 1 ,di + 1});
//				}
//				else
//				{
//					if (cost == 0)
//					{
//						if (dist[ny][nx] > di + 1)
//							q.push({ nx,ny,co,di + 1 });
//					}
//					else
//						q.push({ nx,ny,co,di + 1 });
//				}
//			}
//		}
//	}
//
//	if (dist[N][M] > 1234567)
//		printf("-1");
//	else
//		printf("%d", dist[N][M]);
//
//}