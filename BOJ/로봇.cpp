#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int dx[5] = { 0,1 ,-1,0,0};
int dy[5] = { 0,0 ,0,1,-1};
int M, N;
int map[101][101];
int D[101][101][5];
struct node
{
	int x, y, d, cnt;
	node() {  }
	node(int a, int b, int c, int cn) {
		x = a;
		y = b;
		d = c;
		cnt = cn;
	}
};

int chk(int x, int y)
{
	return x > 0 && x <= N&&y > 0 && y <= M;
}

int main()
{
	
	scanf("%d %d", &M, &N);

	for (int j = 1; j <= M; j++)
		for (int i = 1; i <= N; i++)
			scanf("%d", &map[j][i]);

	int sx, sy, sd, fx, fy, fd;
	scanf("%d %d %d", &sy, &sx, &sd);
	scanf("%d %d %d", &fy, &fx, &fd);

	memset(D, -1, sizeof(D));
	queue<node> q;
	q.push(node(sx, sy, sd, 0));
	while (q.size())
	{
		node t = q.front();
		q.pop();

		if (D[t.y][t.x][t.d] == -1 || D[t.y][t.x][t.d] > t.cnt)
		{
			D[t.y][t.x][t.d] = t.cnt;
			for (int i = 1; i <= 4; i++)
			{

				if (((i-1)/2) != ((t.d-1)/2) && (D[t.y][t.x][i] > t.cnt + 1 || D[t.y][t.x][i] == -1))
					q.push(node(t.x, t.y, i, t.cnt + 1));
			}

			bool flag = 0;
			for (int i = 1; i < 4; i++)
			{
				int tx = t.x + dx[t.d] * i;
				int ty = t.y + dy[t.d] * i;
				if (map[ty][tx] == 1)
					flag = 1;
				if (chk(tx, ty) &&map[ty][tx]==0&& (D[ty][tx][t.d]>t.cnt + 1 || D[ty][tx][t.d] == -1)&&flag==0)
					q.push(node(tx, ty, t.d, t.cnt + 1));
			}
		}
	}
	printf("%d", D[fy][fx][fd]);


}