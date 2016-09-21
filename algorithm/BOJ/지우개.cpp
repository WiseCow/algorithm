#include<cstdio>
#include<cstring>
#define mod 1000000007
typedef long long ll;
int n, map[100001];
ll D[100001][3];
ll sol(int idx, int u)
{
	if (u == 3)
		return 1;
	if (idx > 100000)
		return 0;
	ll &ret = D[idx][u];
	if (ret != -1)
		return ret;
	ret = sol(idx + 1, u);
	if (map[idx])
	{
		ret += (((sol(idx + 1, u + 1)*(ll)idx) % mod)*(ll)map[idx]) % mod;
		ret %= mod;
	}
	return ret;
}
int main()
{
	scanf("%d", &n);
	memset(D, -1, sizeof(D));
	int k;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		map[k]++;
	}
	printf("%lld", sol(0, 0));
}