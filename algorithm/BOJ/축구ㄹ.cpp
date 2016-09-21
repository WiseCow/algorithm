#include<cstdio>
#include<cstring>
int A, B, pri[20] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1};
double D[19][19][19];
double sol(int now, int a, int b)
{
	if (now == 18)
	{
		if (pri[a] || pri[b])
			return 1;
		return 0;
	}
	double &ret = D[now][a][b];
	if (ret != -1.0)return ret;
	ret = 0;
	ret += sol(now + 1, a, b)*(100 - A)*(100 - B) / 10000.0;
	ret += sol(now + 1, a+1, b)*(A)*(100 - B) / 10000.0;
	ret += sol(now + 1, a, b+1)*(100 - A)*(B) / 10000.0;
	ret += sol(now + 1, a+1, b+1)*(A)*(B) / 10000.0;
	return ret;
}
int main()
{
	scanf("%d%d", &A, &B);
	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			for (int k = 0; k < 19; k++)
				D[i][j][k] = -1.0;
	printf("%lf", sol(0, 0, 0));
}