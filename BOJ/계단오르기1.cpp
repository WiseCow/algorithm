#include<cstring>
#include<cstdio>
#define MAX(a,b) a>b?a:b
int N, map[301], D[2][301];
int sol(int step, int now)
{
	if (now == N)return 0;
	int &ret = D[step][now];
	if (ret != -1)return ret;
	ret = -1000;

	if (now + 2 <= N)
		ret = MAX(ret, sol(0, now + 2) + map[now + 2]);
	if (step < 1 && now + 1 <= N)
	{
		if(now==0)
			ret = MAX(ret, sol(step, now + 1) + map[now + 1]);
		else
			ret = MAX(ret, sol(step + 1, now + 1) + map[now + 1]);
	}
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &map[i]);
	memset(D, -1, sizeof(D));
	printf("%d", sol(0, 0));
}