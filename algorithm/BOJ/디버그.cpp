#include<cstdio>
#include<algorithm>
using namespace std;
int R, C;
char map[301][302];
int main()
{
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++)
		scanf("%s", &map[i]);
	int ans = -1;
	for (int i = min(R, C); i >=2; i--)
	{
		for (int j = 0; j <= R - i; j++)
		{
			for (int k = 0; k <= C - i; k++)
			{
				bool chk = 0;
				for (int l = 0; l <= i/2&&!chk; l++)
				{
					for (int m = 0; m < i&&!chk; m++)
					{
						if (map[j+l][k+m] != map[j+i- l-1][k+i- m-1])
							chk = 1;
					}
				}
				if (!chk)
				{
					printf("%d", i);
					return 0;
				}
			}
		}
	}
	printf("%d", ans);


}