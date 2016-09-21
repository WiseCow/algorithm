#include<cstdio>
#include<cstring>
int N,W;
int pol[1004][2];
int D[1004][1004];
bool sel[1004][1004];

int abss(int a)
{
	return a > 0?a:-a;
}
int sol(int p1, int p2, int now)
{
	if (now > W + 1)return 0;
	int &ret = D[p1][p2];
	if (ret != -1)return ret;
	int f1 = sol(now, p2, now+1)+abss(pol[p1][0] - pol[now][0]) + abss(pol[p1][1] - pol[now][1]);
	int f2 = sol(p1,now, now+1) + abss(pol[p2][0] - pol[now][0]) + abss(pol[p2][1] - pol[now][1]);
	if (f1 < f2)
	{
		ret =f1;
		sel[p1][p2] = 0;
	}
	else
	{
		ret =f2;
		sel[p1][p2] = 1;
	}
	return ret;
}
void print(int p1, int p2, int now)
{
	if (now > W + 1)return;
	if (sel[p1][p2])
	{
		printf("2\n");
		print(p1, now, now + 1);
	}
	else
	{
		printf("1\n");
		print(now,p2, now + 1);
	}
}
int main()
{
	memset(D, -1, sizeof(D));
	scanf("%d%d", &N,&W);
	pol[0][0] = pol[0][1] = 1;
	pol[1][0] = pol[1][1] = N;
	for (int i = 2; i <= W + 1; i++)scanf("%d%d", &pol[i][0], &pol[i][1]);
	printf("%d\n", sol(0, 1, 2));
	print(0, 1, 2);

}