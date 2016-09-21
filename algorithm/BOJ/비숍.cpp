//https://www.acmicpc.net/problem/1799
#include<iostream>
using namespace std;
int maxx;
int maxy;
int arr[10][10];
int ngo[10][10];
int xp[100];
int yp[100];
int ptr;
int n;
int _abs(int a)
{
	return a > 0 ? a : -a;
}

void findb(int cnt, int x, int y,int flag)
{

	bool chk = 0;
	for (int i = 0; i < ptr; i++)
	{
		double xg = _abs(x - xp[i]), yg = _abs(y - yp[i]);
		if (xg / yg == 1 || xg / yg == -1)
		{
			chk = 1;
			break;
		}
	}


	if (chk == 1)
		return;
	else
	{
		if (flag == 0)
		{
			if (cnt > maxx)
				maxx = cnt;
			xp[ptr] = x;
			yp[ptr++] = y;

			for (int i = x; i < n; i++)
			{
				int j = 0;
				if (i == x)
					j = y + 1;
				for (; j < n; j++)
				{
					if (arr[i][j] == 1&& (i + j) % 2 == 0)
					{
						findb(cnt + 1, i, j,0);
					}

				}
			}
		}
		else
		{

			if (cnt > maxy)
				maxy = cnt;
			xp[ptr] = x;
			yp[ptr++] = y;

			for (int i = x; i < n; i++)
			{
				int j = 0;
				if (i == x)
					j = y + 1;
				for (; j < n; j++)
				{
					if (arr[i][j] == 1&&(i + j) % 2 == 1)
					{
						findb(cnt + 1, i, j,1);
					}

				}
			}
		}
		ptr--;
	}


}




int main()
{

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}


	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
		{
			if (arr[i][j] == 1)
			{
				if ((i + j) % 2 == 0)
					findb(1, i, j, 0);
				else
					findb(1, i, j, 1);

			}
		}


	printf("%d\n", maxx+maxy);
}