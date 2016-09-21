#include<cstdio>
#include<cstring>
#define inf 987654321
#define min(a,b) ((a)<(b))?(a):(b)
int in[17][17], N,fc;
char on[18];
int D[17][1 << 17];

int sol(int now, int visit)
{
	if (now == fc)
		return 0;
	int &ret = D[now][visit];
	if (ret < inf)return ret;
	int t1 = inf, t2 = inf;
	int c = 0;
	for (int i = 1; i < (1 << N); i <<= 1)
	{
		c++;
		if ((visit&i) == i)
		{
			int k = 0;
			for (int j = 1; j < (1 << N); j <<= 1)
			{
				k++;
				if ((visit&j) != j)
					t1 = min(t1, sol(now + 1, visit | j) + in[c][k]);
			}
		}
	}
	return ret =t1;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &in[i][j]);

	scanf("%s", &on[1]);
	int cnt = 0;
	int onc=0;
	for (int i = 1; i <= N; i++)
	{
		if (on[i] == 'Y')
		{
			cnt++;
			onc |= 1 <<(i-1);
		}
	}
	scanf("%d", &fc);
	memset(D, 0x3f, sizeof(D));

	if (fc == 0)
	{
		if (cnt == 0)
			printf("0");
		else
			printf("-1");
		return 0;
	}
	int res=sol(cnt, onc);
	if (res >= inf)
		printf("-1");
	else
		printf("%d", res);
}