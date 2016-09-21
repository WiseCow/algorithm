#include<cstdio>
typedef long long ll;
int arr[10001];
int K, N;
ll cut(ll mid)
{
	int sum = 0;
	for (int i = 1; i <= K; i++)
		sum += arr[i] / mid;

	return sum;
}


int main()
{
	
	scanf("%d %d", &K, &N);

	ll l = 0, r = 0;

	for (int i = 1; i <= K; i++)
	{
		scanf("%d", &arr[i]);
		r = r > arr[i] ? r : arr[i];
	}
	ll mid;
	ll ans = 0;
	while (l <= r)
	{
		mid = (l + r) / 2;
		ll res = cut(mid);
		if (res >= N) {
			l = mid + 1;
			if (ans < mid)
				ans = mid;
		}
		else
			r = mid-1;
	}

	printf("%lld\n", ans);





}