#include<cstdio>
#include<cstring>
#define mod 1000000007
typedef long long ll;
int N, t,map[100001];
ll D[100001][3];
ll sol(int idx, int use)
{
	if (use == 3)return 1;
	if (idx > 100000)return 0;
	ll &ret = D[idx][use];
	if (ret != -1)return ret;
	ret = sol(idx+1, use);
	if (map[idx])
	{
		ret += (((sol(idx + 1, use + 1)*(ll)idx) % mod)*(ll)map[idx]) % mod;
		ret %= mod;
	}
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &t);
		map[t]++;
	}
	memset(D, -1, sizeof(D));
	printf("%lld",sol(0, 0));
}