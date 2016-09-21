#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> in[32001];
int cnt[32001];
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		in[a].push_back(b);
		cnt[b]++;
	}
	priority_queue<int> q;
	for (int i = 1; i <= N; i++)
		if (cnt[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int w = q.top();
		q.pop();
		printf("%d ", w);
		for (int i = 0; i < in[w].size(); i++)
		{
			cnt[in[w][i]]--;
			if (cnt[in[w][i]] == 0)
				q.push(in[w][i]);
		}
	} 
}

