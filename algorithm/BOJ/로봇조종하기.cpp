#include<cstdio>
#include<cstring>
#define MAX(a,b) a>b?a:b
int N, M, map[1001][1001], D[3][1001][1001];

int sol(int dist, int y, int x)
{
	if (y == N&&x == M)
		return 0;
	int &ret = D[dist][y][x];
	if (ret != -1)return ret;
	ret = -987654321;
	if (y == 0)
		ret = sol(2, 1, 1) + map[1][1];
	else
	{
		if (dist == 0)
		{
			if (y < N)
				ret = MAX(ret, sol(1, y + 1, x) + map[y + 1][x]);
			if (x > 1)
				ret = MAX(ret, sol(0, y, x - 1) + map[y][x - 1]);

		}
		else if (dist == 1)
		{
			if (y < N)
				ret = MAX(ret, sol(1, y + 1, x) + map[y + 1][x]);
			if (x > 1)
				ret = MAX(ret, sol(0, y, x - 1) + map[y][x - 1]);
			if (x < M)
				ret = MAX(ret, sol(2, y, x + 1) + map[y][x + 1]);
		}
		else
		{
			if (y < N)
				ret = MAX(ret, sol(1, y + 1, x) + map[y + 1][x]);
			if (x < M)
				ret = MAX(ret, sol(2, y, x + 1) + map[y][x + 1]);
		}
	}
	return ret;
}


int main()
{
	scanf("%d %d ", &N,&M);
	memset(D, -1, sizeof(D));
	for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++)scanf("%d", &map[i][j]);
	printf("%d\n", sol(0, 0, 0));
}


//
//int main()
//{
//	scanf("%d %d", &N, &M);
//	memset(D, -1, sizeof(D));
//	for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++)scanf("%d", &map[i][j]);
//	printf("%d\n", sol(0,0,0));
//}
//
//#include<cstdio>
//#include<cstring>
//#define MAX(a,b) a>b?a:b
//int N, M, map[1001][1001], D[3][1001][1001];
//
//int sol(int dist, int y, int x)
//{
//	if (y == N&&x == N)
//		return 0;
//	int &ret = D[dist][y][x];
//	if (ret != -1)return ret;
//	ret = -987654321;
//	if (y == 0)
//		ret = sol(2, 1, 1) + map[1][1];
//	else
//	{
//		if (dist == 0)
//		{
//			if (y < N)
//				ret = MAX(ret, sol(1, y + 1, x) + map[y + 1][x]);
//			if (x > 1)
//				ret = MAX(ret, sol(0, y, x - 1) + map[y][x - 1]);
//
//		}
//		else if (dist == 1)
//		{
//			if (y < N)
//				ret = MAX(ret, sol(1, y + 1, x) + map[y + 1][x]);
//			if (x > 1)
//				ret = MAX(ret, sol(0, y, x - 1) + map[y][x - 1]);
//			if (x < N)
//				ret = MAX(ret, sol(2, y, x + 1) + map[y][x + 1]);
//		}
//		else
//		{
//			if (y < N)
//				ret = MAX(ret, sol(1, y + 1, x) + map[y + 1][x]);
//			if (x < N)
//				ret = MAX(ret, sol(2, y, x + 1) + map[y][x + 1]);
//		}
//	}
//	return ret;
//}
//
//
//int main()
//{
//	scanf("%d ", &N);
//	memset(D, -1, sizeof(D));
//	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)scanf("%d", &map[i][j]);
//	printf("%d\n", sol(0, 0, 0));
//}
