
#include <iostream>
using namespace std;
int n, m;
char maze[22][22] = { 0 };

int make[22][22] = { 0 };

int fx[4] = { 0, 1, 0, -1 }, fy[4] = { 1, 0, -1, 0 };

bool chk(int a, int b)
{
	return a >= 0 && b >= 0 && a < n && b < m;
}

int rec = 9999999;
void fun(int x, int y, int cnt)
{

	if (!chk(x, y))
		return;

	if (x == 0 && y == m - 1)
	{
		if (cnt < rec)
			rec = cnt;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (chk(x + fx[i], y + fy[i]) && make[x + fx[i]][y + fy[i]] == 0)
		{
			make[x][y] = cnt;
			fun(x + fx[i], y + fy[i], cnt + 1);
			make[x][y] = 0;
		}

	}
	return;
}
int main()
{
	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		cout << "#testcase" << (itr + 1) << endl;
		cin >> m >> n;

		for (int i = 0; i < n; i++)
		{
			scanf("%s", maze[i]);
			for (int j = 0; j < m; j++)
			{
				if (maze[i][j] == '1')
					make[i][j] = -1;
				else
					make[i][j] = 0;
			}
		}
		rec = 9999999;
		fun(n - 1, 0, 1);
		if (rec == 9999999)
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << rec << endl;
		}
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}
