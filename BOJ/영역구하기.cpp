#include<iostream>
#include<queue>
#define max(a,b) a>b?a:b
#define MIN(a,b) a<=b?a:b
using namespace std;
int map[101][101];
int visit[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int M, N, K;
priority_queue<int> qp;
bool chk(int x, int y)
{
	return x >= 0 && x < M&&y >= 0 && y < N;
}

int dfs(int x, int y)
{
	int res = 0;
	if (!visit[x][y])
	{
		queue < pair<int, int>> q;
		q.push({ x,y });

		while (q.size())
		{
			int qx=q.front().first, qy = q.front().second;
			q.pop();
			
			if (!visit[qx][qy])
			{
				visit[qx][qy] = 1;
				res++;

				for (int i = 0; i < 4; i++)
				{
					int nx = qx + dx[i];
					int ny = qy + dy[i];
					if (chk(nx, ny))
					{
						if (!map[nx][ny] && !visit[nx][ny])
						{
							q.push({ nx,ny });
						}
					}
				}
			}
		}
		qp.push(-res);
	}
		return res;


}


int main()
{
	scanf("%d %d %d", &M, &N, &K);

	for (int itr = 0; itr < K; itr++)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int x = MIN(a,c), y  = MIN(b,d), mx = max(a,c), my = max(b,d);
		for (int i = y; i < my; i++)
		{
			for (int j = x; j < mx; j++)
			{
				if (map[i][j] == 0)
					map[i][j] = 1;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 0 && dfs(i, j))
				res++;
		}
	}


	printf("%d\n", res);

	while (qp.size())
	{
		printf("%d ", -qp.top());
		qp.pop();
	}

	return 0;
}



