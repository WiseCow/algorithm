#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int l,sx,sy,fx,fy;
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
struct Node { int x, y, cost; };
bool chk(int x, int y)
{
	return x >= 0 && x < l&&y >=0 && y < l;
}
int dfs(int map[303][303])
{
	queue<Node>q;
	q.push({ sx,sy,0 });


	while (q.size())
	{
		int x, y, cost;
		x = q.front().x;
		y = q.front().y;
		cost = q.front().cost;
		q.pop();

		if (map[x][y] > cost)
		{
			map[x][y] = cost;


			if (x == fx&&y == fy)
				break;
			for (int i = 0; i < 8; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (chk(nx, ny))
				{
					if (map[nx][ny]>cost + 1)
					{
						q.push({ nx,ny, cost + 1 });
					}
				}
			}
		}
	}


	return map[fx][fy];


}
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{
		scanf("%d", &l);
		scanf("%d %d", &sx, &sy);
		scanf("%d %d", &fx, &fy);
		int map[303][303];
		memset(map, 0x7f, sizeof(map));

		printf("%d\n", dfs(map));
	}



}