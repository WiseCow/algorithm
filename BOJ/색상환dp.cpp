#include<iostream>
using namespace std;
int N, K;
int D[1001][1001];
int main()
{
	scanf("%d %d", &N, &K);


	D[0][0] = D[1][0] = D[2][0] = 1;
	D[2][1] = 2;




}



//#include<iostream>
//#define MOD 100000003
//using namespace std;
//int dp[1001][1001][2];
//int N, K;
//int solve(int a, int sel, int st)
//{
//	if (sel == K)return 1;
//	if (a >= N)return 0;
//
//	int &ret = dp[a][sel][st];
//	if (ret != -1)
//		return ret;
//	else
//		ret = 0;
//
//	if (a == N- 1)
//	{
//		if (st == 1) return 0;
//		ret = (solve(a + 2, sel+1, st) + solve(a + 1, sel, st)) % MOD;
//		return ret;
//	}
//
//
//	if (a == 0)
//		ret = (ret + solve(a + 2, sel+1, 1)) % MOD;
//	else
//		ret = (ret + solve(a + 2, sel+1, st)) % MOD;
//
//
//	if (a == 0)
//		ret = (ret + solve(a + 1, sel, 0)) % MOD;
//	else
//		ret = (ret + solve(a + 1, sel, st)) % MOD;
//
//
//	return ret;
//
//
//}
//
//int main()
//{
//	scanf("%d", &N);
//	scanf("%d", &K);
//
//	for (int i = 0; i < 1001; i++)
//		for (int j = 0; j < 1001; j++)
//		{
//			dp[i][j][0] = -1;
//			dp[i][j][1] = -1;
//		}
//
//
//	printf("%d\n", solve(0,0,0));
//
//}