//https://www.acmicpc.net/problem/2823
#include<iostream>
using namespace std;
char arr[20][20];
int R, C;
bool chk(int i, int j)
{
	if (i >= 0 && i < R&&j >= 0 && j < C)
		return 1;
	else
		return 0;
}
int main()
{
	
	cin >> R >> C;



	for (int i = 0; i < R; i++)
	{
		cin >> arr[i];
	}


	int res = 0;
	int dr[4] = { 1,0,0,-1 };
	int dc[4] = { 0,1,-1,0 };
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] == '.')
			{
				int cnt = 0;
				for (int k = 0; k < 4; k++)
					if (chk(i + dr[k], j + dc[k]) && arr[i + dr[k]][j + dc[k]] == '.')
					{
						cnt++;
					}
				if (cnt == 1)
					res = 1;
			}
		}

	cout << res << endl;
}