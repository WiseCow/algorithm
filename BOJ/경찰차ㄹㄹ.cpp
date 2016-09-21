#include<cstdio>
#include<cstring>
using namespace std;
int D[1001][1001];
int car[1001][2];
bool nextt[1001][1001];
int abs(int a)
{
	return a > 0 ? a : -a;
}
int sol(int p1, int p2, int now, int end)
{
	if (now > end)
		return 0;
	int &ret = D[p1][p2];
	if (ret != -1)return ret;
	int t1 = sol(now, p2, now + 1, end) + abs(car[p1][0] - car[now][0]) + abs(car[p1][1] - car[now][1]);
	int t2 = sol(p1, now, now + 1, end) + abs(car[p2][0] - car[now][0]) + abs(car[p2][1] - car[now][1]);
	if (t1 < t2)
	{
		nextt[p1][p2] = 0;
		ret = t1;
	}
	else
	{
		nextt[p1][p2] = 1;
		ret = t2;
	}
	return ret;
}

void print(int p1, int p2, int now, int end)
{
	if (now > end)
		return;
	printf("%d\n",nextt[p1][p2] + 1);
	if (!nextt[p1][p2])
		print(now, p2, now + 1, end);
	else
		print(p1, now, now + 1, end);
}
int main()
{
	int N;
	scanf("%d", &N);
	car[0][0] = car[0][1] = 1;
	car[1][0] = car[1][1] = N;

	memset(D, -1, sizeof(D));

	int W;
	scanf("%d",&W);
	for (int i = 2; i <= W + 1; i++)
		scanf("%d %d", &car[i][0], &car[i][1]);

	printf("%d\n", sol(0,1,2,W+1));
	print(0, 1, 2, W + 1);
}