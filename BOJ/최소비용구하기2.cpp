#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#define inf 987654321
using namespace std;

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);

	vector<pair<int, int>> in[1001];

	for (int i = 0; i < M; i++)
	{
		int z, b, c;
		scanf("%d %d %d", &z, &b, &c);
		in[z].push_back({ b,c });
	}
	int st, en;
	scanf("%d %d", &st, &en);
	int cost[1001], prev[1001];
	for (int i = 1; i <= N; i++)
		cost[i] = inf;

	queue<int> q;
	for (int i = 0; i < in[st].size(); i++)
	{
		if (cost[in[st][i].first] > in[st][i].second)
		{
			cost[in[st][i].first] = in[st][i].second;
			prev[in[st][i].first] = st;
			q.push(in[st][i].first);
		}
	}


	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < in[now].size(); i++)
		{
			if (cost[in[now][i].first] > cost[now]+in[now][i].second)
			{
				cost[in[now][i].first] = cost[now] + in[now][i].second;
				prev[in[now][i].first] = now;
				q.push(in[now][i].first);
			}
		}
	}


	stack<int> s;
	s.push(en);
	while (s.top() != st)
	{
		s.push(prev[s.top()]);
	}

	printf("%d\n", cost[en]);
	printf("%d\n", s.size());
	while (!s.empty())
	{
		printf("%d ", s.top());
		s.pop();
	}

}