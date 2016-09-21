#include<cstdio>
int coin[101];
int num[101];
int D[101][10010];

int sol(int co, int money)
{
	if (co == 0)
	{
		if (money == 0)
			return 1;
		else
			return 0;
	}
	int &ret = D[co][money];
	if (ret != -1)return ret;
	ret = 0;


	for (int i = 0; i <= num[co]; i++)
	{

		if (money - coin[co] * i < 0)break;
		ret += sol(co - 1, money - coin[co] * i);
	}
	return ret;
}
int main()
{
	int T, k;
	scanf("%d %d", &T, &k);

	for (int i = 1; i <= k; i++)
		scanf("%d %d", &coin[i], &num[i]);

	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= T; j++)
			D[i][j] = -1;


	printf("%d", sol(k, T));

}