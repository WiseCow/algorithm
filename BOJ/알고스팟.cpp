#include<iostream>
#include<queue>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct node
{
	int x, y, cnt;
	node() {}
	node(int a, int b, int c) {
		x = a; y = b; cnt = c;
	}
};
bool chk(int x, int y, int N, int M)
{
	return x > 0 && y > 0 && x <= M&&y <= N;
}
int main()
{
	int M, N;
	char map[102][102];
	int vmap[102][102];
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= N; i++)
		scanf("%s", &map[i][1]);
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= M; j++)
			vmap[i][j] = 987654321;
	queue<node> q;
	q.push(node(1, 1, 0));


	while (q.size())
	{
		node tmp = q.front();
		q.pop();
		int x = tmp.x;
		int y = tmp.y;
		int cnt = tmp.cnt;
		if (map[y][x] == '1')
			cnt += 1;

		if (vmap[y][x] > cnt)
		{
			vmap[y][x] = cnt;
			for (int i = 0; i < 4; i++)
				if (chk(x + dx[i], y + dy[i], N, M) && vmap[y + dy[i]][x + dx[i]]>cnt)
					q.push(node(x + dx[i], y + dy[i], cnt));
		}
	}

	printf("%d", vmap[N][M]);
}