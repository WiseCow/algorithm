//#include<iostream>
//#include<vector>
//#include<queue>
//#define min(a,b) a>b?b:a
//using namespace std;
//int n, m;
//int main()
//{
//	scanf("%d %d", &n, &m);
//	vector<int> want[210];
//	int capacity[210][210] = { 0 }, flow[210][210] = { 0 };
//	for (int i = 1; i <= n; i++)
//	{
//		capacity[0][i] = 1;
//		want[0].push_back(i);
//		want[i].push_back(0);
//	}
//	for (int i = n + 1; i <= n + m; i++)
//	{
//		capacity[i][n + m + 1] = 1;
//		want[i].push_back(n + m + 1);
//		want[n + m + 1].push_back(i);
//	}
//	for (int itr = 1; itr <= n; itr++)
//	{
//		int a, b;
//		scanf("%d", &a);
//		for (int input = 0; input < a; input++)
//		{
//			scanf("%d", &b);
//			want[itr].push_back(n + b);
//			want[n + b].push_back(itr);
//			capacity[itr][n + b] = 1;
//		}
//	}
//	int source = 0, sink = n + m + 1, total = 0;
//
//
//	while (1)
//	{
//		int parent[210] = { 0 };
//		queue<int>q;
//		parent[source] = source;
//		q.push(source);
//		while (q.size() && parent[sink] == 0)
//		{
//			int here = q.front();
//			q.pop();
//			for (int i = 0; i < want[here].size(); i++)
//			{
//				int there = want[here][i];
//				int capa = capacity[here][there];
//				if (capa - flow[here][there]>0 && parent[there] == 0)
//				{
//					q.push(there);
//					parent[there] = here;
//				}
//			}
//		}
//		if (parent[sink] == 0)break;
//		int amount = 987654321;
//		for (int p = sink; p != source; p = parent[p])
//		{
//			amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
//		}
//
//		for (int p = sink; p != source; p = parent[p])
//		{
//			flow[p][parent[p]] -= amount;
//			flow[parent[p]][p] += amount;
//		}
//		total += amount;
//	}
//
//	printf("%d", total);
//}
//
#include<iostream>
#include<vector>
#include<queue>
#define min(a,b) a<b?a:b
using namespace std;
int capacity[410][410] = { 0 }, flow[410][410] = { 0 },total=0;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> want[410];
	for (int i = 1; i <= n; i++)
	{
		want[0].push_back(i);
		want[i].push_back(0);
		capacity[0][i] = 1;
	}
	for (int i = n+1; i <= n+m; i++)
	{
		want[i].push_back(n+m+1);
		want[n+m+1].push_back(i);
		capacity[i][n+m+1] = 1;
	}

	for (int itr = 1; itr <= n; itr++)
	{
		int a, b;
		scanf("%d", &a);
		for (int k = 0; k < a; k++)
		{
			scanf("%d", &b);
			want[itr].push_back(n +b);
			want[n + b].push_back(itr);
			capacity[itr][n + b] = 1;
		}
	}
	int src = 0, sink = n + m + 1;
	while(1)
	{
		queue<int> q;
		q.push(src);
		int parent[410] = { 0 };

		while (q.size() && parent[sink] == 0)
		{
			int here = q.front();
			q.pop();
			

			for (int i = 0; i < want[here].size(); i++)
			{
				int there = want[here][i];
				int capa = capacity[here][there];
				if (capa - flow[here][there]>0 && parent[there] == 0)
				{
					parent[there] = here;
					q.push(there);
				}
			}
		}
		int amount = 987654321;
		if (parent[sink] == 0) break;
		for (int p = sink; p != src; p = parent[p])
		{
			amount = min(amount, capacity[parent[p]][p]-flow[parent[p]][p]);
		}
		for (int p = sink; p != src; p = parent[p])
		{
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		total += amount;
	}
	
	printf("%d", total);

}