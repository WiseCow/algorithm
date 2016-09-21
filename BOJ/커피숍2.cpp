#include<cstdio>
typedef long long ll;
using namespace std;
ll arr[100001];
ll tree[400004];
int N, Q;
ll init(int left, int right, int node)
{
	if (left == right)
		return tree[node] = arr[left];
	int mid = (left + right) / 2;
	ll left_ret = init(left, mid, node * 2);
	ll right_ret = init(mid + 1, right, node * 2 + 1);
	return tree[node] = left_ret + right_ret;
}
ll query(ll left, ll right, ll N_left, ll N_right, ll node)
{
	if (right < N_left || N_right < left)
		return 0;
	if (left <= N_left&&N_right <= right)
		return tree[node];
	int mid = (N_left + N_right) / 2;
	ll Lquery = query(left, right, N_left, mid, node * 2);
	ll Rquery = query(left, right, mid + 1, N_right, node * 2 + 1);
	return Lquery + Rquery;
}
ll update(ll idx, ll value, ll N_left, ll N_right,ll node)
{
	if (idx<N_left || N_right<idx)
		return tree[node];
	if (N_left == N_right)
		return tree[node] = value;

	int mid = (N_left + N_right) / 2;
	ll Lupdate = update(idx, value, N_left, mid, node * 2);
	ll Rupdate = update(idx, value, mid+1, N_right, node * 2+1);
	return tree[node] = Lupdate + Rupdate;
}

int main()
{
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);
	init(0, N - 1, 1);
	for (int i = 0; i < Q; i++)
	{
		ll a, b, c, d;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		ll mi = a < b ? a : b;
		ll mx = a >= b ? a : b;
		printf("%lld\n", query(mi - 1, mx - 1, 0, N - 1, 1));
		update(c - 1, d, 0, N - 1, 1);
	}
}