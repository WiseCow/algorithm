#include<cstdio>
#include<queue>
using namespace std;
int H, W;
char map[1000][1001];
int sand[1000][1000];
queue<pair<int, int>> q1, q2;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 },dy[8] = { -1,-1,0,1,1,1,0,-1 };
int main()
{
	scanf("%d %d", &H, &W);
	for (int i = 0; i < H; i++)
		scanf("%s", &map[i]);
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{
			if (map[i][j] != '.')
			{
				for (int k = 0; k < 8; k++)
				{
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx >= 0 && nx < W&&ny >= 0 && ny < H)
					{
						if (map[ny][nx] == '.')
							sand[i][j]++;
					}
				}
				if ((map[i][j] - '0') <= sand[i][j])
					q1.push({ j, i });
			}
		}

	int total;
	for (int i = 1;; i++)
	{
		int cnt = 0;
		if ((i % 2) == 1)
		{
			while (q1.size())
			{
				int x = q1.front().first;
				int y = q1.front().second;
				q1.pop();
				for (int k = 0; k < 8; k++)
				{
					int nx = x + dx[k];
					int ny = y + dy[k];
					sand[ny][nx]++;
					if (sand[ny][nx] == map[ny][nx] - '0')
					{
						q2.push({ nx,ny });
						cnt++;
					}
				}
			}
			if (cnt == 0)
			{
				total = i;
				break;
			}
		}
		else
		{
			while (q2.size())
			{
				int x = q2.front().first;
				int y = q2.front().second;
				q2.pop();
				for (int k = 0; k < 8; k++)
				{
					int nx = x + dx[k];
					int ny = y + dy[k];
					sand[ny][nx]++;
					if (sand[ny][nx] == map[ny][nx] - '0')
					{
						q1.push({ nx,ny });
						cnt++;
					}
				}
			}
			if (cnt == 0)
			{
				total = i;
				break;
			}
		}
	}
	printf("%d", total);

}
