#include<iostream>
#include<vector>
using namespace std;
struct Edge
{
	int s, e, c;
	Edge() {}
	Edge(int a,int b, int d) {
		s = a;  e=b; c = d;
	}
};
int main()
{

	int N, M;
	scanf("%d %d", &N, &M);

	vector<Edge> in;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a,&b, &c);
		in.push_back(Edge(a, b, c));
	}
	int D[501];
	for (int i = 0; i <= N; i++)
		D[i] = 987654321;
	
	D[1] = 0;
	bool chk = 0;
	for (int j = 1; j <= N; j++)
	{
		for (int k = 0; k < M; k++)
		{
			int from = in[k].s;
			int to = in[k].e;
			int cost = in[k].c;
			if (D[to] > D[from] + cost)
			{
				D[to] = D[from] + cost;
				if (j == N)chk = 1;
			}
		}
	}


	if (chk == 1)
		printf("-1\n");
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (D[i] == 987654321)
				printf("-1\n");
			else
				printf("%d\n", D[i]);
		}
	}


	return 0;

}
//#include <vector>
//#include <queue>
//#include <iostream>
//using namespace std;
//
//int n, m, a, b, c;
//struct node {
//	int to, cost;
//};
//
//vector<node> v[502];
//int cnt[502], d[502];
//bool chk[502];
//const int inf = 1987654321;
//int main()
//{
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < m; i++)
//	{
//		scanf("%d %d %d", &a, &b, &c);
//		v[a].push_back({ b, c });
//	}
//
//	for (int i = 1; i <= n; i++)
//		d[i] = inf;
//
//	d[1] = 0;
//	chk[1] = true;
//	queue < int>q;
//	q.push(1);
//
//	while (q.size())
//	{
//		int from = q.front();
//		chk[from] = false;
//		q.pop();
//
//		for (int i = 0; i < v[from].size(); i++)
//		{
//			int to = v[from][i].to;
//			int cost = v[from][i].cost;
//			if (d[to] > d[from] + cost)
//			{
//				d[to] = d[from] + cost;
//				if (chk[to] == false)
//				{
//					q.push(to);
//					chk[to] = true;
//					cnt[to] += 1;
//					if (cnt[to] >= n)
//					{
//						printf("-1\n");
//						return 0;
//					}
//				}
//			}
//		}
//	}
//
//	for (int i = 2; i <= n; i++)
//		if (d[i] == inf)
//			printf("-1\n");
//		else
//			printf("%d\n", d[i]);
//	return 0;
//}