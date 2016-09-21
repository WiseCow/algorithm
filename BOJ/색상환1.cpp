#include<iostream>
#define MOD 1000000003
using namespace std;
int N, K, memo[1001][1001][2];


int sol(int i, int sel, int first)
{
	if (sel == K)return 1;
	if (i >= N)return 0;

	int &ret = memo[i][sel][first];
	if (ret != -1)return ret;
	ret = 0;

	if (i == N - 1)
	{
		if (first == 1)
			return 0;
		ret = (sol(i + 2, sel + 1, first) + sol(i + 1, sel, first)) % MOD;
		return ret;
	}

	if (i == 0)
		ret =(ret + sol(i + 2, sel + 1, 1)) % MOD;
	else 
		ret= (ret + sol(i + 2, sel + 1, first)) % MOD;

	if (i == 0)
		ret = (ret + sol(i + 1, sel, 0)) % MOD;
	else
		ret = (ret + sol(i + 1, sel, first)) % MOD;

	return ret;
}

int main()
{
	scanf("%d", &N); scanf("%d", &K);
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			memo[i][j][0] = memo[i][j][1] = -1;
		}
	}

	printf("%d", sol(0, 0, 0));
}