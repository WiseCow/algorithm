//https://www.acmicpc.net/problem/1389
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	vector<int> arr[101];
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	int max = 99999999;
	int p = 0;

	for (int i = 1; i < N; i++)
	{


		queue<pair<int, int>> q;
		int visit[101] = { 0 };
		visit[i] = -1;
		for (int k = 0; k < arr[i].size(); k++)
			q.push(make_pair(arr[i][k], 1));

		while (!q.empty())
		{
			auto a = q.front();
			int next = a.first;
			int dist = a.second;
			q.pop();
			if (visit[next] == 0 || visit[next]>dist)
			{
				visit[next] = dist;
				for (int w = 0; w < arr[next].size(); w++)
				{
					if (visit[arr[next][w]] == 0 || visit[arr[next][w]]>dist + 1)
					{
						q.push(make_pair(arr[next][w], dist + 1));
					}
				}
			}
		}
		int sum = 0;
		for (int i = 1; i <= N; i++)
			sum += visit[i];


		if (max > sum)
		{
			p = i;

			max = sum;
		}
	}

	cout << p << endl;
}