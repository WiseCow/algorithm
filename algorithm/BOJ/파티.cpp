#include <iostream>
#include <queue>
#include <functional> 
#include <vector>
#define max(a,b) a>b?a:b
#define INF 999999999
typedef long long ll;
using namespace std;
vector <pair<ll, ll>> road[10001];
int N, M, X;

int find(int st, int end)
{
	vector <ll> rec(N+1,INF);
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> qq;
	qq.push(make_pair(0, st));

	rec[st] = 0;
	while (!qq.empty())
	{
		int here = qq.top().second;
		int here_dis = qq.top().first;
		if (here_dis > rec[here])
		{
			qq.pop();
			continue;
		}
		for (int i = 0; i< road[here].size(); i++)
		{
			int there = road[here][i].first;
			int there_dis = road[here][i].second;
			if (rec[there] > here_dis + there_dis)
			{
				rec[there] = here_dis + there_dis;
				qq.push(make_pair(here_dis + there_dis, there));
			}
		}
		qq.pop();
	}
	return rec[end];
}


int main()
{
	scanf("%d %d %d", &N, &M, &X);


	for (int itr = 0; itr < M; itr++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		road[a].push_back(make_pair(b, c));
	}

	int mmax = 0;
	for (int i = 1; i <= N; i++)
	{
		mmax = max(mmax, find(i, X) + find(X, i));
	}
	cout << mmax << endl;
	return 0;
}