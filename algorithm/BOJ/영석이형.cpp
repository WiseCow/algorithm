#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

struct M
{
	char arr[5][5];
	int cnt;
};


bool CC(int x, int y)
{
	if (x < 0 || y < 0 || x >= 3 || y >= 3)
		return false;
	else
		return true;
}
bool check(M x)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (x.arr[i][j] == '*')
				return false;
		}
	}
	return true;
}
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int main(void)
{
	int test;
	scanf("%d", &test);
	for (int tcnt = 0; tcnt < test; tcnt++)
	{
		queue<M > q;
		M m = { 0, };
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				char tmp;
				cin >> tmp;
				m.arr[i][j] = tmp;
			}
		}

		q.push(m);
		int cnt = 987654321;
		while (!q.empty())
		{
			M a = q.front();
			q.pop();
			if (check(a) == true)
			{
				if (cnt > a.cnt)
					cnt = a.cnt;
			}

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (a.arr[i][j] == '*')
					{
						M tmp = a;
						tmp.arr[i][j] = '.';
						for (int k = 0; k < 4; k++)
						{
							if (CC(i + dx[k], j + dy[k]) == true)
								tmp.arr[i + dx[k]][j + dy[k]] = '.';
						}
						tmp.cnt++;
						q.push(tmp);
					}
				}
			}
		}
		printf("%d \n", cnt);
	}

	return 0;
}