#include<iostream>
using namespace std;
int coin[101];
int num[101];
int D[101][10010];

int find(int ci,int money)
{
	if (ci == 0)
	{
		if (money == 0)
			return 1;
		else
			return 0;
	}
	int &ret = D[ci][money];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i <= num[ci]; i++)
	{
		if (money - coin[ci] * i < 0)break;
		ret += find(ci - 1, money - coin[ci] * i);
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
		for (int m = 0; m <= T; m++)
			D[i][m] = -1;
	printf("%d", find(k, T));
}
//#include <stdio.h>
//int T, K;
//int coin[111];
//int num[111];
//int cache[111][10010];
//int dp(int index, int money) 
//{
//	if (index == -1) 
//	{
//		if (money == 0) return 1;
//		else return 0;
//	}
//	int&ret = cache[index][money];
//	if (ret != -1) return ret;
//	int i, j;
//	ret = 0;
//	for (i = 0; i <= num[index]; i++) 
//	{
//		if (money - coin[index] * i < 0) break;
//		ret += dp(index - 1, money - coin[index] * i);
//	}
//	return ret;
//}
//int main(void) {
//	int i, j, k;
//	scanf("%d%d", &T, &K);
//	for (i = 0; i < K; i++)
//	{
//		scanf("%d%d", &coin[i], &num[i]);
//	}
//	for (i = 0; i <= K; i++)
//		for (j = 0; j <= T; j++)
//			cache[i][j] = -1;
//
//
//	printf("%d\n", dp(K - 1, T));
//	return 0;
//}


