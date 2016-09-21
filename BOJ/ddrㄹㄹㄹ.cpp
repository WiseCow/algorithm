#include<cstdio>
#include<cstring>
#define inf 987654321
int in[100001], D[100001][5][5];
int idx = 1;
int abs(int a){return a > 0 ? a : -a;}
int sol(int now, int l, int r)
{
	if (now == idx-1)
		return 0;
	int &ret = D[now][l][r];
	if (ret != -1)return ret;
	int t1 = inf;
	int t2 = inf;
	if (l == in[now + 1])
		t1 = sol(now + 1, in[now + 1], r) + 1;
	else if (r == in[now + 1])
		t2 = sol(now + 1, l, in[now + 1]) + 1;
	else if (l == 0)
	{
		t1 = sol(now + 1, in[now + 1], r) + 2;
		t2 = sol(now + 1, l, in[now + 1]) + (abs(r - in[now + 1]) == 2 ? 4 : 3);
	}
	else if (r == 0)
	{
		t1 = sol(now + 1, in[now + 1], r) + (abs(l - in[now + 1]) == 2 ? 4 : 3);
		t2 = sol(now + 1, l, in[now + 1]) + 2;
	}
	else
	{
		t1 = sol(now + 1, in[now + 1], r) + (abs(l - in[now + 1]) == 2 ? 4 : 3);
		t2 = sol(now + 1, l, in[now + 1])+ (abs(r - in[now + 1]) == 2 ? 4 : 3);
	}
	return ret = t1 < t2 ? t1 : t2;
}
int main()
{
	while (1)
	{
		scanf("%d", &in[idx]);
		if (in[idx] == 0)
			break;
		idx++;
	}
	memset(D, -1, sizeof(D));
	printf("%d", sol(0, 0, 0));
}