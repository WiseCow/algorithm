#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int weight[10001];
vector<int> edge[10001];
int trip[10001];
int dp[10001][2];
int solve(int now, int par) {
	for (int i = 0; i<edge[now].size(); i++) {
		int there = edge[now][i];
		if (there == par)
			continue;
		solve(there, now);
	}
	dp[now][0] = 0;
	dp[now][1] = weight[now];
	for (int i = 0; i<edge[now].size(); i++) {
		int there = edge[now][i];
		if (there == par)
			continue;
		dp[now][0] += max(dp[there][1], dp[there][0]);
		dp[now][1] += dp[there][0];
	}
	return max(dp[now][0], dp[now][1]);
}
vector<int> ans;
void get_ans(int now, int par, bool s) {
	if (s) {
		ans.push_back(now);
		for (int i = 0; i<edge[now].size(); i++) {
			int there = edge[now][i];
			if (there == par)
				continue;
			get_ans(there, now, 0);
		}
		return;
	}
	for (int i = 0; i<edge[now].size(); i++) {
		int there = edge[now][i];
		if (there == par)
			continue;
		if (dp[there][0]>dp[there][1])
			get_ans(there, now, 0);
		else
			get_ans(there, now, 1);
	}
	return;
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &weight[i]);
	for (int i = 0; i<N - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	edge[0].push_back(1);
	printf("%d\n", solve(0, 0));
	get_ans(0, 0, 0);
	for (auto i : ans)
		printf("%d ", i);
	printf("\n");
	return 0;
}