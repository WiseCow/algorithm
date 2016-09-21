#include <cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
int N, K, S;
bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
	return a.first > b.first;
}

ll sol(vector<pair<ll, ll>> vc)
{
	ll ans = 0, bus = K;
	for (int i = 0; i < vc.size();)
	{
		ll &dis = vc[i].first;
		ll &man = vc[i].second;
		if (bus == 0)
			bus = K;
		if (man == 0)
		{
			i++;
			continue;
		}
		if (man > bus)
		{
			if (bus == K)
			{
				ans += dis + dis;
				man -= K;
			}
			else
			{
				man -= bus;
				bus = 0;
			}
		}
		else if (man <= bus)
		{
			if (bus == K)
				ans += dis + dis;
			bus -= man;
			man = 0;
		}
	}
	return ans;
}
int main() {
	vector<pair<ll, ll> > left;
	vector<pair<ll, ll> > right;

	scanf("%d %d %d", &N, &K, &S);

	for (ll i = 0; i < N; i++) {
		int n, m;
		scanf("%d %d", &n, &m);
		if (n < S)
			left.push_back(make_pair(S - n, m));
		else
			right.push_back(make_pair(n - S, m));
	}
	sort(left.begin(), left.end(), cmp);
	sort(right.begin(), right.end(), cmp);

	ll ans = 0;
	ans += sol(left);
	ans += sol(right);
	printf("%d",ans);
}