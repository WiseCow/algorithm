#include<iostream>
#include<queue>
using namespace std;
int N, M, dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 }, vmap[1011][1011][2];
char map[1011][1011];
struct node
{
	int x, y, cnt;
	bool chk;
	node(int a, int b, int c, bool d)
	{
		x = a; y = b; cnt = c; chk = d;
	}
};
bool chkxy(int x, int y){return x > 0 && y > 0 && x <= M&&y <= N;}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%s", &map[i][1]);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			vmap[i][j][0] = vmap[i][j][1] = 987654321;
	queue<node> q;
	q.push(node(1, 1, 1, 0));
	while (q.size())
	{
		node tmp = q.front();
		q.pop();
		int x = tmp.x, y = tmp.y, cnt = tmp.cnt;
		bool chk = tmp.chk;
		if (!chk)
		{
			if (vmap[y][x][0] > cnt)
			{
				vmap[y][x][0] = cnt;
				if (vmap[y][x][1] > cnt)
					vmap[y][x][1] = cnt;
				for (int i = 0; i < 4; i++)
					if (chkxy(x + dx[i], y + dy[i]))
					{
						if (map[y + dy[i]][x + dx[i]] == '0'&&vmap[y + dy[i]][x + dx[i]][0]>cnt + 1)
							q.push(node(x + dx[i], y + dy[i], cnt + 1, 0));
						if (map[y + dy[i]][x + dx[i]] == '1')
							q.push(node(x + dx[i], y + dy[i], cnt + 1, 1));
					}
			}
		}
		else
		{
			if (vmap[y][x][1] > cnt)
			{
				vmap[y][x][1] = cnt;
				for (int i = 0; i < 4; i++)
					if (chkxy(x + dx[i], y + dy[i]))
						if (map[y + dy[i]][x + dx[i]] == '0'&&vmap[y + dy[i]][x + dx[i]][0]>cnt + 1)
							q.push(node(x + dx[i], y + dy[i], cnt + 1, 1));
			}
		}
	}
	int a = vmap[N][M][0];
	int b = vmap[N][M][1];
	if (a < b)
		if (a >= 987654321)
			printf("-1");
		else
			printf("%d", a);
	else
		if (b >= 987654321)
			printf("-1");
		else
			printf("%d", b);
}