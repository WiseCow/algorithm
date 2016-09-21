#include<cstdio>
#include<cstring>
char in[1001];
int D[1001][31][3];
int T, W;
int sol(int now, int move, int last)
{
	if (now == T+1)return 0;

	int &ret = D[now][move][last];
	if (ret != -1)
		return ret;
	int t1 = 0, t2 = 0;

	if (last == in[now])
		t1 = sol(now + 1, move, last) + 1;
	else
	{
		if(move<W)
			t1 = sol(now + 1, move + 1, in[now]) + 1;
		t2 = sol(now + 1, move, last);
	}
	return ret = t1 > t2 ? t1 : t2;
}


int main()
{
	scanf("%d %d", &T, &W);
	for (int i = 1; i <= T; i++)
		scanf("%d", &in[i]);
	memset(D, -1, sizeof(D));

	printf("%d", sol(1,0, 1));
}