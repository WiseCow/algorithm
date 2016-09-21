#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	vector<int> in[501];
	int cost[501];
	int cnt[501] = { 0 };
	int last[501] = { 0 };
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &cost[i]);
		while (1)
		{
			int t;
			scanf("%d", &t);
			if (t == -1)
				break;
			in[t].push_back(i);
			cnt[i]++;
		}
	}
	priority_queue<int>q;
	for (int i = 1; i <= N; i++)
		if (cnt[i] == 0)
			q.push(i);


	while (q.size())
	{
		int tmp = q.top();
		q.pop();

		for (int i = 0; i < in[tmp].size(); i++)
		{
			cnt[in[tmp][i]]--;
			if (last[in[tmp][i]] < last[tmp] + cost[tmp])
				last[in[tmp][i]] = last[tmp] + cost[tmp];

			if (cnt[in[tmp][i]] == 0)
				q.push(in[tmp][i]);
		}
	}


	for (int i = 1; i <= N; i++)
		printf("%d\n", last[i] + cost[i]);





}