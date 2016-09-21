#include<iostream>
using namespace std;
int N;
char in[102][102];
int visit[102][102];
int visit1[102][102];
int v = 1;
int v1 = 1;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };




void find(int a, int b,char c)
{
	if (!visit[a][b])
	{
		visit[a][b] = v;
		for (int i = 0; i < 4; i++)
		{
			int x = a + dx[i];
			int y = b + dy[i];


			if (x >= 1 && x <= N&&y >= 1 && y <= N&&!visit[x][y])
			{
				
					if (c == in[x][y])
						find(x, y, c);
			}
		}
	}
}

void find1(int a, int b, char c)
{
	if (!visit1[a][b])
	{
		visit1[a][b] = v1;
		for (int i = 0; i < 4; i++)
		{
			int x = a + dx[i];
			int y = b + dy[i];


			if (x >= 1 && x <= N&&y >= 1 && y <= N&&!visit1[x][y])
			{
					if (c == in[x][y] || (c == 'R'&&in[x][y] == 'G') || (c == 'G'&&in[x][y] == 'R'))
						find1(x, y, c);
			}
		}
	}
}
int main()
{
	scanf("%d", &N);


	for (int i = 1; i <= N; i++)
	{
		scanf("%s", &in[i][1]);
	}


	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (!visit[i][j])
			{
				find(i, j, in[i][j]);
				v++;
			}
		}


	for (int i = 1;i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (!visit1[i][j])
			{
				find1(i, j, in[i][j]);
				v1++;
			}
		}



	cout << v - 1 << " " << v1 - 1 << '\n';




}