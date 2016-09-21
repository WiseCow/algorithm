#include<iostream>
#include<queue>

using namespace std;
int N;
char map[53][53];
int D[51][51];
int dx[] = { -1,0,1,0 };
int dy[] = { 0, 1, 0, -1 };

struct node
{
	int x, y, cnt;
	node(int a, int b, int c) { x = a; y = b; cnt = c; }
};

int main()
{

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%s", &map[i][1]);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			D[i][j] = 987654321;


	queue<node> q;
	q.push(node(1, 1, 0));

	while (!q.empty())
	{
		node tmp = q.front();
		q.pop();
		if (D[tmp.x][tmp.y] > tmp.cnt)
		{
			D[tmp.x][tmp.y] = tmp.cnt;
			for (int i = 0; i < 4; i++)
			{
				int x = tmp.x + dx[i];
				int y = tmp.y + dy[i];

				if (x > 0 && x <= N&&y > 0 && y <= N)
				{
					if (map[x][y] == '1'&&D[x][y] > tmp.cnt)
					{
						q.push(node(x, y, tmp.cnt));
					}
					if (map[x][y] == '0'&&D[x][y] > tmp.cnt + 1)
					{
						q.push(node(x, y, tmp.cnt + 1));
					}

				}
			}
		}
	}

	printf("%d\n", D[N][N]);
}