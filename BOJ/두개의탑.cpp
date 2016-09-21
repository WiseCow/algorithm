#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
int n, map[50001];
ll sum;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &map[i]);
		sum += map[i];
	}
	int st = 0, en = 0;
	ll temp = 0;
	ll ans = 0;
	while (1)
	{
		while (sum - temp > temp)
		{
			temp += map[en++];
			en %= n;
			ans = max(ans, min(sum - temp, temp));
		}
		temp -= map[st];
		ans = max(ans, min(sum - temp, temp));
		st++;
		st %= n;
		if (st == 0) break;
	}
	printf("%lld", ans);
}
