#include<cstdio>
using namespace std;
typedef long long ll;
ll arr[100002];
ll tree[400008];
int N, Q;
ll init(int left, int right,int  node)
{
	if (left == right)
		return tree[node] = arr[left];
	int mid = (left + right) / 2;
	ll left_ret = init(left, mid, node * 2);
	ll right_ret = init(mid + 1, right, node * 2 + 1);
	return tree[node] = left_ret + right_ret;
}
ll update(int idx, int value, int node_left, int node_right, int node)
{
	if (idx < node_left || node_right<idx)
		return tree[node];
	if (node_left == node_right)
		return tree[node] = value;


	int mid = (node_left + node_right) / 2;
	ll left_ret = update(idx, value, node_left, mid, node * 2);
	ll right_ret = update(idx, value, mid + 1, node_right, node * 2 + 1);
	return tree[node] = left_ret + right_ret;
}

ll query(int left, int right, int node_left, int node_right, int node)
{
	if (right < node_left || node_right < left)
		return 0;
	if (left <= node_left&&node_right <= right)
		return tree[node];
	int mid = (node_left + node_right) / 2;
	ll left_ret = query(left, right, node_left, mid, node * 2);
	ll right_ret = query(left, right, mid + 1, node_right, node * 2 + 1);
	return left_ret + right_ret;
}


int main()
{
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; i++)scanf("%lld%", &arr[i]);
	init(0, N - 1, 1);
	for (int i = 0; i < Q; i++)
	{
		ll a, b, c, d;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		ll mini = a < b ? a : b;
		ll maxi = a >= b ? a : b;
		printf("%lld\n", query(mini-1, maxi-1, 0, N - 1, 1));
		update(c - 1, d, 0, N - 1, 1);
	}
}