#include<cstdio>
#include<cstring>
#include<vector>
#define dump 3000000
using namespace std;
int D[51][51], map[50][50], N;
int pluus[dump + dump];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	D[0][0] = map[0][0];
	for (int i = 1; i < N; i++)
	{
		D[0][i] = D[0][i - 1] + map[0][i];
		D[i][0] = D[i - 1][0] + map[i][0];
	}
	for (int i = 1; i < N; i++)
		for (int j = 1; j < N; j++)
			D[i][j] = D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1] + map[i][j];
	int cnt = 0;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			for (int k = 0; k < i; k++)
			{
				for (int h = 0; h < j; h++)
				{
					int now = D[i - 1][j - 1];
					if (k>0)
						now -= D[k - 1][j - 1];
					if (h>0)
						now -= D[i - 1][h - 1];
					if (k>0 && h>0)
						now += D[k - 1][h - 1];
					pluus[now + dump]++;
				}
			}
			for (int k = i; k < N; k++)
			{
				for (int h = j; h < N; h++)
				{
					int now = D[k][h];
					if (i>0)
						now -= D[i - 1][h];
					if (j>0)
						now -= D[k][j - 1];
					if (i>0 && j>0)
						now += D[i - 1][j - 1];
					cnt += pluus[now + dump];
				}
			}

			for (int k = 0; k < i; k++)
			{
				for (int h = 0; h < j; h++)
				{
					int now = D[i - 1][j - 1];
					if (k>0)
						now -= D[k - 1][j - 1];
					if (h>0)
						now -= D[i - 1][h - 1];
					if (k>0 && h>0)
						now += D[k - 1][h - 1];
					pluus[now + dump]--;
				}
			}
			for (int k = 0; k < i; k++)
			{
				for (int h = j; h < N; h++)
				{
					int now = D[i - 1][h];
					if (k>0)
						now -= D[k - 1][h];
					if (j>0)
						now -= D[i - 1][j - 1];
					if (k>0 && j>0)
						now += D[k - 1][j - 1];
					pluus[now + dump]++;
				}
			}
			for (int k = i; k < N; k++)
			{
				for (int h = 0; h < j; h++)
				{
					int now = D[k][j - 1];
					if (i > 0)
						now -= D[i - 1][j - 1];
					if (h > 0)
						now -= D[k][h - 1];
					if (i > 0 && h > 0)
						now += D[i - 1][h - 1];
					cnt += pluus[now + dump];
				}
			}

			for (int k = 0; k < i; k++)
			{
				for (int h = j; h < N; h++)
				{
					int now = D[i - 1][h];
					if (k>0)
						now -= D[k - 1][h];
					if (j>0)
						now -= D[i - 1][j - 1];
					if (k>0 && j>0)
						now += D[k - 1][j - 1];
					pluus[now + dump]--;
				}
			}
		}
	}



	printf("%d", cnt);
	return 0;
}