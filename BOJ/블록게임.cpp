#include<cstdio>
char input[204][208];
int map[202][202], N, M, K, idx;
double ff;
int visit[10001];
void makemap(int x, int y)
{
	map[y][x] = map[y + 1][x] = map[y + 1][x + 1] = map[y][x + 1] = idx;
	if (input[y + 1][x + 2] == '.'&&!map[y][x + 2])
		makemap(x + 2, y);
	if (input[y + 2][x + 1] == '.'&&!map[y + 2][x])
		makemap(x, y + 2);
	if (input[y + 1][x] == '.'&&!map[y][x - 2])
		makemap(x - 2, y);
	if (input[y][x + 1] == '.'&&!map[y - 2][x])
		makemap(x, y - 2);

}
void serch(int x, int y, int dist)
{
	if ((dist == 3 || dist == 4) && y == (M * 2))
		return;
	visit[map[y][x]] = 1;
	if (dist == 1)
	{
		if (x == 0 && y == 0)
		{
			serch(x, y, 3);
		}
		else if (x == 0)
		{
			serch(x, y - 1, 2);
		}
		else if (y == 0)
		{
			serch(x - 1, y, 4);
		}
		else
		{
			serch(x - 1, y - 1, 1);
		}
	}
	else if (dist == 2)
	{

		if (x == (N * 2 - 1) && y == 0)
		{
			serch(x, y, 4);
		}
		else if (x == (N * 2 - 1))
		{
			serch(x, y - 1, 1);
		}
		else if (y == 0)
		{
			serch(x + 1, y, 3);
		}
		else
		{
			serch(x + 1, y - 1, 2);
		}
	}
	else if (dist == 3)
	{
		if (x == (N * 2 - 1))
		{
			serch(x, y + 1, 4);
		}
		else
		{
			serch(x + 1, y + 1, 3);
		}
	}
	else
	{
		if (x == 0)
		{
			serch(x, y+1, 3);
		}
		else
		{
			serch(x - 1, y + 1, 4);
		}
	}
}
int main()
{
	scanf("%d %d %lf", &N, &M, &ff);
	K = ff + ff;
	for (int i = 0; i <= M * 2; i++)
		scanf("%s", &input[i]);
	for (int i = 1; i <= M * 2; i += 2)
	{
		for (int j = 1; j <= N * 2; j += 2)
		{
			if (input[i][j] == 'B'&&!map[i - 1][j - 1])
			{
				idx++;
				makemap(j - 1, i - 1);
			}
		}
	}
	serch(K, M * 2, 1);
	int cnt = 0;
	for (int i = 1; i <= idx; i++)
		if (visit[i])cnt++;
	printf("%d", cnt);
}