#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int D[501][501];
int N, K;

int sol(int n, int k)
{
	if (n == 0)
		return 0;
	if (k == 0)
		return 0x3f3f3f3f;
	int &ret = D[n][k];
	if (ret != -1)return ret;
	ret = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		ret = min(ret, max(sol(i - 1, k - 1) + 1, sol(n - i, k) + 1));
	}
	return ret;
}
int main()
{
	scanf("%d%d", &N, &K);
	memset(D, -1, sizeof(D));
	printf("%d", sol(N, K));
}