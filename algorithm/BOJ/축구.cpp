#include<cstdio>
double D[19][19][19];
int A, B;
bool prime[20] = { 0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1 };
double sol(int idx, int a, int b)
{
	if (idx == 18)
	{
		if (prime[a] || prime[b])
			return 1;
		else
			return 0;
	}
	double &ret = D[idx][a][b];
	if (ret != -1.0)return ret;
	ret = 0;
	ret += sol(idx + 1, a, b)*(100 - A)*(100 - B) / 10000.0;
	ret += sol(idx + 1, a+1, b)*(A)*(100 - B) / 10000.0;
	ret += sol(idx + 1, a, b+1)*(100 - A)*(B) / 10000.0;
	ret += sol(idx + 1, a+1, b+1)*(A)*(B) / 10000.0;
	return ret;
}
int main()
{
	for (int i = 0; i < 18; i++)
		for (int j = 0; j < 20; j++)
			for (int k = 0; k < 20; k++)
				D[i][j][k] = -1.0;
	scanf("%d %d", &A, &B);
	printf("%lf", sol(0,0,0));
}