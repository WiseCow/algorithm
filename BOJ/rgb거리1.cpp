#include<cstdio>
#include<cstring>
#define MIN(a,b) a<b?a:b
#define INF 987654321
int N, map[3][1001], D[3][1001];
int sol(int col, int now)
{
	if (now > N)return INF;
	if (now == N)return map[col][now];
	int &ret = D[col][now];
	if (ret != -1)return ret;
	ret = INF;
	if (col != 0 || now == 0)
		ret = MIN(ret, sol(0, now + 1) + map[col][now]);
	if (col != 1 || now == 0)
		ret = MIN(ret, sol(1, now + 1) + map[col][now]);
	if (col != 2 || now == 0)
		ret = MIN(ret, sol(2, now + 1) + map[col][now]);
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d %d", &map[0][i], &map[1][i], &map[2][i]);
	memset(D, -1, sizeof(D));
	printf("%d", sol(0, 0));
}