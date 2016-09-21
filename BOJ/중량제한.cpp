#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node
{
	int B, dist;
	node(int a,  int c)
	{
		B = a;
		dist = c;
	}
};

int main()
{
	int  N, M;

	scanf("%d %d", &N, &M);

	vector<pair<int, int>> arr[10001];

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d ", &a, &b, &c);
		arr[a].push_back(make_pair(b, c));
		arr[b].push_back(make_pair(a, c));

	}
	int s, f;
	scanf("%d %d", &s, &f);

	int qp = 0;
	for (int lp = 0; lp < arr[s].size(); lp++)
	{
		int distarr[100001] = { 0 };
		distarr[s] = 999999999;

		queue<node> q;
		auto au = arr[s][lp];
		q.push(node(au.first,au.second));
		distarr[au.first] = au.second;

		while (!q.empty())
		{
			int B = q.front().B;
			int dist = q.front().dist;
	
			for (int i = 0; i < arr[B].size(); i++)
			{
				int next = arr[B][i].first;
				int distn = arr[B][i].second>dist ? dist : arr[B][i].second;
				if (distarr[next] == 0)
				{
					distarr[next] = distn;
					q.push(node(next, distn));
				}
				else if(distarr[next]<distn)
				{
					distarr[next] = distn;
					q.push(node(next, distn));
				}
			}
			q.pop();
		}
		if (qp < distarr[f])
			qp = distarr[f];
	}
	cout << qp << endl;
}