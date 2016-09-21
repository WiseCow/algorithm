#include<cstdio>
#include<algorithm>
#define MAX(a,b) a>b?a:b
using namespace std;
int n, maxx = 0;
char map[51][52];
void findR(int i,bool chk)
{		char tmp = 0;
		int now = 0;
		if (!chk) {
			for (int k = 0; k < n; k++)
			{
				if (tmp == map[i][k])
				{
					now++;
					maxx = MAX(maxx, now);
				}
				else
				{
					tmp = map[i][k];
					now = 1;
				}
			}
		}
		else
		{
			for (int k = 0; k < n; k++)
			{
				if (tmp == map[k][i])
				{
					now++;
					maxx = MAX(maxx, now);
				}
				else
				{
					tmp = map[k][i];
					now = 1;
				}
			}
		}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", &map[i]);
	for (int i = 0; i < n; i++)
	{
		findR(i,0);
		findR(i,1);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < n - 1&&map[i][j]!=map[i][j+1])
			{
				swap(map[i][j], map[i][j + 1]);
				findR(i,0);findR(j,1);	findR(j + 1,1);
				swap(map[i][j], map[i][j + 1]);
			}
			if (i<n-1 && map[i][j] != map[i+1][j])
			{
				swap(map[i][j],map[i+1][j]);
				findR(i,0);findR(i+1,0);findR(j,1);
				swap(map[i][j], map[i + 1][j]);
			}
		}
	}
	printf("%d", maxx);
}