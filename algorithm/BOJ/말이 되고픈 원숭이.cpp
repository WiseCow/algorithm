#include<iostream>
#include<queue>
#include<cstring>
#define min(a,b) (a)>(b)?(b):(a)
using namespace std;
int K,W,H;
int map[202][202];
int dist[31][202][202];
int px[8] = { 1,2,2,1,-1,-2,-2,-1};
int py[8] = { -2,-1,1,2,2,1,-1,-2};
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct Node {
	int x, y, cost, dist;
};
bool chk(int x, int y)
{
	return x > 0 && x <= W&&y > 0 && y <= H;
}
int main()
{
	scanf("%d %d %d", &K, &W, &H);

	for (int i = 1; i <= H; i++)for (int j = 1; j <= W; j++)scanf("%d", &map[i][j]);
	memset(dist, 0x7f, sizeof(dist));
	queue<Node> q;

	q.push({ 1,1,0,0 });

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
		if (x == W&&y == H)
			break;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (chk(nx, ny) && dist[co][ny][nx]>di + 1&&map[ny][nx]==0)
				q.push({ nx,ny,co,di + 1 });
		}
		if (co < K)
		{
			for (int i = 0; i < 8; i++)
			{
				int nx = x + px[i], ny = y + py[i];
				if (chk(nx, ny) && dist[co+1][ny][nx]>di + 1 && map[ny][nx] == 0)
					q.push({ nx,ny,co+1,di + 1 });
			}
		}
	}
	int mini = dist[0][H][W];
	for (int i = 1; i <= K; i++)
	{
		mini = min(mini, dist[i][H][W]);
	}
	if (mini > 12345678)
		printf("-1");
	else
		printf("%d", mini);
}



//#include<iostream>
//#include<queue>
//#include<cstring>
//using namespace std;
//int K, W, H;
//int arr[202][202];
//int costmap[202][202];
//int distmap[202][202];
//int px[8] = { 1,2,2,1,-1,-2,-2,-1 };
//int py[8] = { -2,-1,1,2,2,1,-1,-2 };
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { -1,0,1,0 };
//struct Node {
//	int x, y, kk, cost;
//};
//
//queue<Node> q;
//
//bool chk(int x, int y)
//{
//	return x > 0 && x <= W&&y > 0 && y <= H;
//}
//int bfs()
//{
//	while (q.size())
//	{
//		Node tmp = q.front();
//		q.pop();
//		int x = tmp.x;
//		int y = tmp.y;
//		int kk = tmp.kk;
//		int cost = tmp.cost;
//		if (cost < distmap[y][x])
//		{
//			distmap[y][x] = cost;
//			costmap[y][x] = kk;
//			if (y == H&&x == W)
//				break;
//
//			if (kk > 0)
//				for (int i = 0; i < 8; i++)
//				{
//					int nx = x + px[i];
//					int ny = y + py[i];
//					if (chk(nx, ny))
//					{
//						if (distmap[ny][nx] >= cost + 1)
//						{
//							q.push({ nx,ny, kk - 1,cost + 1 });
//						}
//					}
//				}
//
//			for (int i = 0; i < 4; i++)
//			{
//				int nx = x + dx[i];
//				int ny = y + dy[i];
//				if (chk(nx, ny))
//				{
//					if (distmap[ny][nx]>cost + 1)
//					{
//						q.push({ nx,ny, kk,cost + 1 });
//					}
//				}
//			}
//		}
//		else if (cost == distmap[y][x])
//		{
//			if (kk > costmap[y][x])
//			{
//
//				distmap[y][x] = cost;
//				costmap[y][x] = kk;
//				if (kk > 0)
//					for (int i = 0; i < 8; i++)
//					{
//						int nx = x + px[i];
//						int ny = y + py[i];
//						if (chk(nx, ny))
//						{
//							if (distmap[ny][nx] >= cost + 1)
//							{
//								q.push({ nx,ny, kk - 1,cost + 1 });
//							}
//						}
//
//					}
//				for (int i = 0; i < 4; i++)
//				{
//					int nx = x + dx[i];
//					int ny = y + dy[i];
//					if (chk(nx, ny))
//					{
//						if (distmap[ny][nx]>cost + 1)
//						{
//							q.push({ nx,ny, kk,cost + 1 });
//						}
//					}
//				}
//			}
//		}
//	}
//	if (distmap[H][W] < 7654321)
//		return distmap[H][W];
//	else
//		return -1;
//
//
//
//}
//
//int main()
//{
//
//	scanf("%d", &K);
//	scanf("%d %d", &W, &H);
//
//	for (int i = 1; i <= H; i++)
//	{
//		for (int j = 1; j <= W; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	q.push({ 0,0,K,0 });
//
//	memset(costmap, 0x7f, sizeof(costmap));
//	memset(distmap, 0x7f, sizeof(distmap));
//	int res = bfs();
//	printf("%d", res);
//}
