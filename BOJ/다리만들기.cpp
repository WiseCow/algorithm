#include<iostream>
#include<queue>
#define MIN(a,b) ((a)<(b))?a:b
using namespace std;
int n, map[101][101], gro[101][101],use[101][101], dx[4] = {1, 0, -1, 0}, dy[4] = { 0, -1, 0 ,1};
struct Node {
	int x, y, gr,cnt;
};
queue<Node> qqq;
bool chk(int x, int y)
{
	return x > 0 && y > 0 && x <= n&&y <= n;
}
bool grouping(int y, int x, int gr)
{
	if (gro[y][x] == 0)
	{
		queue<pair<int, int>>q;
		q.push({ y,x });
		while (q.size())
		{
			int nowy = q.front().first;
			int nowx = q.front().second;
			q.pop();
			if (gro[nowy][nowx] != 0)continue;
			gro[nowy][nowx]=gr;
			for (int i = 0; i < 4; i++)
			{
				int nx=nowx+dx[i], ny=nowy+dy[i];
				if (chk(nx, ny))
				{
					if (map[ny][nx] == 1&&gro[ny][nx]==0)
					{
						q.push({ ny,nx });
					}
					if (map[ny][nx] == 0)
					{
						qqq.push({ nx,ny,gr ,1});
					}
				}
			}
		}
		return 1;
	}
	else
		return 0;
}

int find()
{
	bool cck = 0;
	int now;
	int mini = 9999999999;
	while (qqq.size())
	{
		int x = qqq.front().x;
		int y = qqq.front().y;
		int gr = qqq.front().gr;
		int cnt = qqq.front().cnt;
		qqq.pop();
		if (cck)
		{
			if (cnt == now)
			{
				if (gro[y][x] == gr)continue;
				else if (gro[y][x] != 0)
				{
					mini =MIN(mini, use[y][x] + cnt - 1);
				}
			}
			else
				return mini;

		}
		else {
			if (gro[y][x] == gr)continue;
			else if (gro[y][x] != 0)
			{
				cck = 1;
				now = cnt;
				mini = use[y][x] + cnt - 1;
			}
		}
			
		gro[y][x] = gr;
		use[y][x] = cnt;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (chk(nx, ny))
			{
				if (gro[ny][nx] != gr)
					qqq.push({ nx,ny,gr,cnt + 1 });
			}
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)scanf("%d", &map[i][j]);
	int gr = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (map[i][j] == 1 && grouping(i, j, gr))
			{
				gr++;
			}
	}
	printf("%d", find());
	return 0;
}