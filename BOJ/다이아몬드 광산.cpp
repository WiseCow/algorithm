#include<cstdio>
#include<algorithm>
using namespace std;
int R, C;
char map[800][800];
int dmap[4][800][800];
void makedmap()
{
	for (int i = 0; i < R; i++)
	{
		int tr = i, tc = 0, c = 0;
		for (; tr >= 0 && tc < C; tr--&tc++)
		{
			if (map[tr][tc] == '1')
				c++;
			else
				c = 0;
			dmap[0][tr][tc] = c;
		}
		tr = i;
		tc = C - 1;
		c = 0;
		for (; tr >= 0 && tc >= 0; tr--&tc--)
		{
			if (map[tr][tc] == '1')
				c++;
			else
				c = 0;
			dmap[1][tr][tc] = c;
		}

		tr = i;
		tc = 0;
		c = 0;
		for (; tr < R&&tc < C; tr++&tc++)
		{
			if (map[tr][tc] == '1')
				c++;
			else
				c = 0;
			dmap[2][tr][tc] = c;
		}
		tr = i;
		tc = C - 1;
		c = 0;
		for (; tr < R&&tc >= 0; tr++&tc--)
		{
			if (map[tr][tc] == '1')
				c++;
			else
				c = 0;
			dmap[3][tr][tc] = c;
		}
	}

	for (int i = 0; i < C; i++)
	{
		int tr = R - 1, tc = i, c = 0;
		for (; tc < C&&tr >= 0; tr--&tc++)
		{
			if (map[tr][tc] == '1')
				c++;
			else
				c = 0;
			dmap[0][tr][tc] = c;
		}
		tr = R - 1;
		tc = i;
		c = 0;
		for (; tr >= 0 && tc >= 0; tr--&tc--)
		{
			if (map[tr][tc] == '1')
				c++;
			else
				c = 0;
			dmap[1][tr][tc] = c;
		}

		tr = 0;
		tc = i;
		c = 0;
		for (; tc < C&&tr < R; tr++&tc++)
		{
			if (map[tr][tc] == '1')
				c++;
			else
				c = 0;
			dmap[2][tr][tc] = c;
		}

		tr = 0;
		tc = i;
		c = 0;
		for (; tc >= 0 && tr < R; tr++&tc--)
		{
			if (map[tr][tc] == '1')
				c++;
			else
				c = 0;
			dmap[3][tr][tc] = c;
		}
	}



}
int main()
{
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)
		scanf("%s", &map[i]);
	makedmap();
	int maxxx = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			int u, d;
			u = min(dmap[0][i][j], dmap[1][i][j]);
			if (u > maxxx)
			{
				for (; u >= 0; u--)
				{
					if (i + (u - 1) * 2 < R)
					{
						d = min(dmap[2][i + (u - 1) * 2][j], dmap[3][i + (u - 1) * 2][j]);
						if (d >= u)
							maxxx = max(maxxx, d);
					}
				}
			}
		}
	}

	printf("%d", maxxx);
}