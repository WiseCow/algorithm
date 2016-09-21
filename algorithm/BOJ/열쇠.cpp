//https://www.acmicpc.net/problem/9328
#include<iostream>
#include<queue>
#include<utility>

using namespace std;
char map[100][100];
int sx[400], sy[400], stp;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };


bool able(int x, int y, int mx, int my)
{
	if (x >= 0 && x < mx&&y >= 0 && y < my)
		return 1;
	else
		return 0;
}


int main()
{
	int tc;
	scanf("%d", &tc);

	for (int itr = 0; itr < tc; itr++)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		for (int i = 0; i < x; i++)
		{
			scanf("%s", &map[i]);
		}
		char key[40];
		scanf("%s", &key);
		int keyc[26] = { 0 };
		for (int i = 0; key[i] != 0; i++)
		{
			if (key[i] == '0')
				break;
			else
				keyc[key[i] - 'a']++;
		}
		stp = 0;

		for (int i = 0; i < y; i++)
		{
			if (map[0][i] != '*')
			{
				sx[stp] = 0;
				sy[stp++] = i;
			}
			if (map[x - 1][i] != '*')
			{
				sx[stp] = x - 1;
				sy[stp++] = i;
			}
		}
		for (int i = 1; i < x - 1; i++)
		{
			if (map[i][0] != '*')
			{
				sx[stp] = i;
				sy[stp++] = 0;
			}
			if (map[i][y - 1] != '*')
			{
				sx[stp] = i;
				sy[stp++] = y - 1;
			}
		}

		queue <pair<int, int>> q;
		int ste = 0;
		bool flag = 1;

		while (flag == 1)
		{
			flag = 0;
			int  visit[101][101] = { 0 };
			for (int i = 0; i < stp; i++)
				q.push(make_pair(sx[i], sy[i]));

			while (!q.empty())
			{
 				auto a = q.front();
				int kx = a.first;
				int ky = a.second;
				q.pop();
				if (visit[kx][ky] == 0)
				{
					visit[kx][ky] = 1;
					int know = map[kx][ky];
					if (know >= 'A'&&know <= 'Z'&&keyc[know - 'A'] == 0)
						continue;
					if (know == '$')
					{
						ste++;
						map[kx][ky] = '.';
					}

					for (int i = 0; i < 4; i++)
					{
						if (able(kx + dx[i], ky + dy[i], x, y) && map[kx + dx[i]][ky + dy[i]] != '*'&&visit[kx + dx[i]][ky + dy[i]] == 0)
						{
							char now = map[kx + dx[i]][ky + dy[i]];
							if (now == '.')
								q.push(make_pair(kx + dx[i], ky + dy[i]));
							else if (now >= 'A'&&now <= 'Z')
							{
								if (keyc[now - 'A'] != 0)
									q.push(make_pair(kx + dx[i], ky + dy[i]));
							}
							else if (now == '$')
							{
								
								ste++;
								map[kx + dx[i]][ky + dy[i]] = '.';
								q.push(make_pair(kx + dx[i], ky + dy[i]));
							}
							else
							{
								keyc[now - 'a']++;
								map[kx + dx[i]][ky + dy[i]] = '.';
								q.push(make_pair(kx + dx[i], ky + dy[i]));
								flag = 1;
							}
						}
					}
				}
			}
		}
		
		printf("%d\n", ste);
	}




}