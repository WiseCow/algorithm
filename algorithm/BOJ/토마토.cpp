#include<iostream>
#include<queue>
#define inf 987654321
using namespace std;
struct node
{
	int x;
	int y;
	int cnt;
	node(int a, int b, int c) { x = a; y = b; cnt = c; }
};
int map[1001][1001];
int visit[1001][1001];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int main()
{

	int M, N;
	scanf("%d %d", &M, &N);
	queue<node> q;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
			{
				q.push(node(i, j, 0));
			}
			visit[i][j] = inf;
		}


	int maxcnt = 0;
	while (q.size())
	{
		node tmp = q.front();
		q.pop();
		
		if (visit[tmp.x][tmp.y] > tmp.cnt)
		{
			visit[tmp.x][tmp.y] = tmp.cnt;
			maxcnt = maxcnt > tmp.cnt ? maxcnt : tmp.cnt;
			for (int i = 0; i < 4; i++)
			{
				int x = tmp.x+dx[i];
				int y = tmp.y+dy[i];
				int cnt = tmp.cnt;

				if (x > 0 && x <= N&&y > 0 && y <= M &&  visit[x][y] > cnt + 1 && (map[x][y] == 0 || map[x][y] == 1))
					q.push(node(x, y, cnt + 1));
			}
		}
	}

	bool chk = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if ((map[i][j] == 0 || map[i][j] == 1) && visit[i][j] == inf)
				chk = 1;
		}


	if (chk == 0)
		printf("%d\n", maxcnt);
	else
		printf("-1\n");

	return 0;
}