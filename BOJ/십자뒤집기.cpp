#include<iostream>
using namespace std;
int dx[5] = { 0,-1,0,1,0 };
int dy[5] = { 0,0,-1,0,1 };
int mcnt = 987654321;

void findmap(int click[10],int idx,char map[5][5],int white, int cnt)
{
	if (cnt == 10)
		return;

	click[idx]++;
	int x = idx / 3 + 1;
	int y = idx % 3;
	if (y == 0)
	{
		x--;
		y = 3;
	}
	for (int i = 0; i < 5; i++)
	{
		if (x + dx[i]>= 1 && x+ dx[i] <= 3 && y + dy[i] >= 1 && y + dy[i] <= 3)
		{

			if (map[x + dx[i]][y + dy[i]] == '.')
			{
				map[x + dx[i]][y + dy[i]] = '*';
				white--;
			}
			else
			{
				map[x + dx[i]][y + dy[i]] = '.';
				white++;
			}
		}
	}

	if (white == 9)
	{
		int a = 0;
		for (int i = 1; i < 10; i++)
		{
				a+=click[i];
		}
		if (mcnt > a)
			mcnt = a;
	}
	else
	{
		for (int i = idx+1; i < 10; i++)
		{
			if (click[i] ==0)
			findmap(click, i, map, white,cnt+1);
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (x + dx[i] >= 1 && x + dx[i] <= 3 && y + dy[i] >= 1 && y + dy[i] <= 3)
		{

			if (map[x + dx[i]][y + dy[i]] == '.')
			{
				map[x + dx[i]][y + dy[i]] = '*';
			}
			else
			{
				map[x + dx[i]][y + dy[i]] = '.';
			}
		}
	}
	click[idx]--;

}
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{
		mcnt = 987654321;
		char map[5][5];
		

		for (int i = 1; i <= 3; i++)
			scanf("%s", &map[i][1]);

		int click[10] = { 0 };
		int white = 0;
		for (int i = 1; i < 4; i++)
			for (int j = 1; j < 4; j++)
			{
				if (map[i][j] == '.')
					white++;
			}

		if (white != 9)
			for (int i = 1; i < 10; i++)
			{

				findmap(click, i, map, white,1);
			}
		else
			mcnt = 0;
		cout << mcnt << '\n';

	}



}