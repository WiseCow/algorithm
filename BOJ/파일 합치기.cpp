#include<cstdio>
#include<cstring>
#define MIN(a,b) ((a)<(b))?a:b
#define INF 987654321;
typedef long long ll;
int n, map[501],sec[501];
ll D[501][501];
ll sol(int s, int f)
{
	if (s == f)return 0;
	ll &ret = D[s][f];
	if (ret != -1)return ret;
	ret = INF;
	for (int i = s; i < f; i++)
	{
		ll st = sol(s, i)+sec[i]-sec[s-1];
		ll en = sol(i+1, f)+sec[f]-sec[i];
		ret = MIN(ret, st + en);
	}
	return ret;
}
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{
		scanf("%d", &n);
		for (int in = 1; in <= n; in++) {
			scanf("%d", &map[in]);
			sec[in] = sec[in - 1] + map[in];
		}
		memset(D, -1, sizeof(D));
		printf("%lld\n", sol(1, n));
	}
}