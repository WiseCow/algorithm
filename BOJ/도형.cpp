#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int N, K, in[50000];
ll D[50][10][50000];
ll sol(int idx, int kidx, int sum)
{
	if (kidx == K)
	{
		if (in[idx-1] >= sum - in[idx-1])
			return 0;
		else
			return 1;
	}
	if (idx == N)
		return 0;
	ll &ret = D[idx&1][kidx][sum];
	if (ret != -1)return ret;
	ret = 0;
	ret += sol(idx +1, kidx + 1, sum + in[idx]);
	ret += sol(idx +1, kidx, sum);
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &in[i]);
	scanf("%d", &K);
	sort(in, in + N);
	memset(D, -1, sizeof(D));
	printf("%lld", sol(0, 0, 0));
}