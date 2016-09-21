#include<cstdio>
#include<cstring>
int sec[1002][2];
int position[1001][1001];
int D[1002][1002];
int abs(int a){return a > 0  ? a : -a;}
int min(int a, int b){return a > b ? a : b;}
int sol(int p1, int p2, int now, int end)
{

	if (now > end) return 0;

	int &ret = D[p1][p2];
	if (ret != -1)
		return ret;

	int fp1 = sol(now, p2, now + 1, end) + abs(sec[now][0] - sec[p1][0]) + abs(sec[now][1] - sec[p1][1]);
	int fp2 = sol(p1, now, now + 1, end) + abs(sec[now][0] - sec[p2][0]) + abs(sec[now][1] - sec[p2][1]);
	if (fp1 > fp2)
	{
		position[p1][p2] = 2;
		ret = fp2;
	}
	else
	{
		position[p1][p2] = 1;
		ret = fp1;
	}
	return ret;
}


void print(int p1, int p2, int now, int end)
{
	if (now > end)return;
	printf("%d\n", position[p1][p2]);
	if (position[p1][p2] == 1)
		print(now, p2, now + 1, end);
	else
		print(p1, now, now + 1, end);
}



int main()
{
	int N, W;
	scanf("%d %d", &N, &W);
	memset(D, -1, sizeof(D));
	sec[0][0] = sec[0][1] = 1;
	sec[1][0] = sec[1][1] = N;
	for (int i = 2; i <= W+1; i++)
		scanf("%d %d", &sec[i][0], &sec[i][1]);
	printf("%d\n", sol(0, 1, 2, W + 1));

	print(0, 1, 2, W + 1);
	return 0 ;
}





//#include <cstdio>
//#include <cstring>
//
//int Abs(int a) { return (a < 0) ? -a : a; }
//int Min(int a, int b) { return a < b ? a : b; }
//
//using namespace std;
//
//int d[1005][1005];
//int b[1005][1005];
//int p[1005][2];
//
//int search(int c1, int c2, int now, int lim)
//{
//	if (now > lim) return 0;
//
//	int &ret = d[c1][c2];
//
//	if (ret != -1) return ret;
//
//	int rc1 = search(now, c2, now + 1, lim) + Abs(p[now][0] - p[c1][0]) + Abs(p[now][1] - p[c1][1]);
//	int rc2 = search(c1, now, now + 1, lim) + Abs(p[now][0] - p[c2][0]) + Abs(p[now][1] - p[c2][1]);
//
//	if (rc1 < rc2)
//	{
//		b[c1][c2] = 1;
//		ret = rc1;
//	}
//	else
//	{
//		b[c1][c2] = 2;
//		ret = rc2;
//	}
//
//	return ret;
//}
//
//void chk(int c1, int c2, int now, int lim)
//{
//	if (now > lim) return;
//
//	printf("%d\n", b[c1][c2]);
//	if (b[c1][c2] == 1)
//	{
//		chk(now, c2, now + 1, lim);
//	}
//	else
//	{
//		chk(c1, now, now + 1, lim);
//	}
//
//	return;
//}
//
//int main()
//{
//	int n, w;
//
//	scanf("%d %d", &n, &w);
//
//	p[0][0] = 1;
//	p[0][1] = 1;
//	p[1][0] = n;
//	p[1][1] = n;
//
//	memset(d, -1, sizeof(d));
//
//	for (int i = 2; i <= w + 1; i++)
//	{
//		scanf("%d %d", &p[i][0], &p[i][1]);
//	}
//
//	printf("%d\n", search(0, 1, 2, w + 1));
//
//	chk(0, 1, 2, w + 1);
//
//
//	return 0;
//}