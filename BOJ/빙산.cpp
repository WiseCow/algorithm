#include<iostream>
#include<queue>
using namespace std;
struct Node { int x, y, cost; };
queue<Node> q1, q2;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int N, M;
bool check(int x, int y)
{
	return x > 0 && x <= N&&y > 0 && y <= M;
}

bool dfs(int map[301][301], bool visit[301][301],int x,int y,int chk)
{
	if (chk == 1)
	{
		if (visit[x][y]==0)
		{
			visit[x][y] = 1;
			
			if (map[x][y]!=0)
			{

				int a = 0;
				for (int i = 0; i < 4; i++)
				{
					if (check(x + dx[i], y + dy[i]))
					{
						if (map[x + dx[i]][y + dy[i]] == 0 && visit[x + dx[i]][y + dy[i]] == 0)
							a++;
					}
				}
				map[x][y] -= a;
				if (map[x][y] < 0)
					map[x][y] = 0;
				if (map[x][y] != 0)
				q2.push({ x,y, map[x][y] });
			}


			for (int i = 0; i < 4; i++)
			{
				if (check(x + dx[i], y + dy[i])&&map[x+dx[i]][y+dy[i]]-1>=0)
				{
					dfs(map, visit, x + dx[i], y + dy[i], chk);
				}
			}
			return 1;
		}
		else
			return 0;
	}
	else
	{
		if (visit[x][y] == 0)
		{
			visit[x][y] = 1;

			if (map[x][y] != 0)
			{
				int a = 0;
				for (int i = 0; i < 4; i++)
				{
					if (check(x + dx[i], y + dy[i]))
					{
						if (map[x + dx[i]][y + dy[i]] == 0 && visit[x + dx[i]][y + dy[i]] == 0)
							a++;
					}
				}
				map[x][y] -= a;

				if (map[x][y] < 0)
					map[x][y] = 0;
				if (map[x][y] != 0)
				q1.push({ x,y, map[x][y] });
			}

			for (int i = 0; i < 4; i++)
			{
				if (check(x + dx[i], y + dy[i]) && map[x + dx[i]][y + dy[i]] - 1 >= 0)
				{
					dfs(map, visit, x + dx[i], y + dy[i], chk);
				}
			}
			return 1;
		}
		else
			return 0;

	}


}

int main()
{
	
	int map[301][301];

	scanf("%d %d", &N, &M);



	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j]!=0)
			q1.push({ i,j,map[i][j] });
		}
	}
	
	int res = 0;
	
	if (q1.size() == 0)
	{
		printf("0");
		return 0;
	}

	for (int i = 0; i <= 10000&&(q1.size()||q2.size()); i++)
	{
		bool visit[301][301] = { 0 };
		int itr = 0;
		if (i % 2 == 0)
		{
		
			while(q1.size())
			{
				int x = q1.front().x;
				int y = q1.front().y;
				q1.pop();
				if (dfs(map, visit, x, y, 1))
				{
					itr++;
				}
				
			}
			if (itr==1&&q2.size() == 0)
			{
				res = 0;
				break;
			}
		}
		else
		{

			while(q2.size())
			{
				int x = q2.front().x;
				int y = q2.front().y;
				q2.pop();
				if (dfs(map, visit, x, y, 2))
				{
					itr++;
				}
				
			}
			if (itr == 1 && q1.size() == 0)
			{
				res = 0;
				break;
			}

		}
		if (itr > 1)
			break;
		else
			res++;
	}

		printf("%d", res);

}