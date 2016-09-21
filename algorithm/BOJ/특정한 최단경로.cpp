#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define inf 987654321
#define min(a,b) ((a)>(b))?b:a
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second > b.second;
}


int main()
{
	int N, E;
	scanf("%d %d", &N, &E);

	vector<pair<int, int>> in[801];
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		in[a].push_back({ b,c });
		in[b].push_back({ a,c });
	}
	int A, B;
	scanf("%d %d", &A, &B);
	long long D[801][3];
	for (int i = 0; i <= N; i++)
	{
		D[i][0] = D[i][1] = D[i][2] = inf;
		sort(in[i].begin(), in[i].end(), cmp);
	}

	queue<int> q;
	q.push(1);
	D[1][0] = 0;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		for (int i = 0; i < in[t].size(); i++)
		{
			if (D[in[t][i].first][0]>D[t][0] + in[t][i].second)
			{
				D[in[t][i].first][0] = D[t][0] + in[t][i].second;
				q.push(in[t][i].first);
			}
		}
	}

	q.push(A);
	D[A][1] = 0;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		for (int i = 0; i < in[t].size(); i++)
		{
			if (D[in[t][i].first][1]>D[t][1] + in[t][i].second)
			{
				D[in[t][i].first][1] = D[t][1] + in[t][i].second;
				q.push(in[t][i].first);
			}
		}
	}

	q.push(B);
	D[B][2] = 0;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		for (int i = 0; i < in[t].size(); i++)
		{
			if (D[in[t][i].first][2]>D[t][2] + in[t][i].second)
			{
				D[in[t][i].first][2] = D[t][2] + in[t][i].second;
				q.push(in[t][i].first);
			}
		}
	}


	long long res = D[A][0] + D[B][1] + D[N][2];
	res = min(res, D[B][0] + D[A][2] + D[N][1]);
	if(res >= inf)
		res = -1;

	printf("%lld\n", res);









}