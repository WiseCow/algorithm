//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//queue<int> q;
//vector <int> arr[10];
//bool visit[10] = { 0 };
//
//bool qvisit[10] = { 0 };
//void DFS(int now)
//{
//	printf("%d->", now);
//	visit[now] = 1;
//	for (int i = 0; i < arr[now].size(); i++)
//	{
//		if (!visit[arr[now][i]])
//			DFS(arr[now][i]);
//	}
//}
//void BFS()
//{
//	while (!q.empty())
//	{
//		int print = q.front();
//		q.pop();
//		if (!qvisit[print])
//		{
//			printf("%d->", print);
//			qvisit[print] = 1;
//		}
//	}
//}
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//
//
//	q.push(1);
//	for (int itr = 0; itr < b; itr++)
//	{
//		int aa, bb;
//		scanf("%d %d ", &aa, &bb);
//		arr[aa].push_back(bb);
//		q.push(bb);
//	}
// 	DFS(1);
//	cout << endl;
//	BFS();
//
//}

//
//#include<iostream>
//#include<vector>
//using namespace std;
//vector<int> vec[1001];
//bool visit[1001];
//int DFS(int now,bool chk)
//{
//	if (visit[now] == 0)
//	{
//		visit[now] = 1;
//		for (int i = 0; i < vec[now].size(); i++)
//		{
//			if (!visit[vec[now][i]])
//				DFS(vec[now][i], 0);
//		}
//		if (chk == 1)
//			return 1;
//		else
//			return 0;
//	}
//	else
//		return 0;
//}
//int main()
//{
//	int N, M;
//
//	scanf("%d %d", &N, &M);
//	for (int itr = 0; itr < M; itr++)
//	{
//		int a, b;
//		scanf("%d %d", &a, &b);
//		vec[a].push_back(b);
//	}
//
//	int sum=0;
//
//
//	for (int i = 1; i <= N; i++)
//	{
//		sum+=DFS(i, 1);
//	}
//
//
//
//
//	printf("%d", sum);
//
//}

//
//#include<iostream>
//#include<queue>
//#include<vector>
//#include<functional>
//using namespace std;
//
//int main()
//{
//
//	priority_queue <vector<pair<int, int>>, vector<pair<int, int >>, greater<pair<int, int>>> pq;
//
//	bool visit[1001] = { 0 };
//
//	vector <  pair<int, int>> vc[1001];
//	int a, b;
//	scanf("%d %d ", &a, &b);
//
//
//
//	for (int itr = 0; itr < b; itr++)
//	{
//		int aa, bb, cc;
//		scanf("%d %d %d", &aa, &bb, &cc);
//		vc[aa].push_back({ bb,cc });
//		vc[bb].push_back({ aa,cc });
//	}
//	visit[1] = 1;
//
//	for (int i = 0; i < vc[1].size(); i++)
//		pq.push({ vc[1][i].second, vc[1][i].first });
//
//	int ans = 0;
//
//	for (int i = 0; i<a - 1; i++)
//	{
//		pair<int, int> e;
//		while (!pq.empty())
//		{
//			e = pq.top();
//			pq.pop();
//			if (visit[e.second] == false)
//			{
//				break;
//			}
//		}
//		visit[e.second] = true;
//		ans += e.first;
//		int x = e.second;
//		for (int i = 0; i<vc[x].size(); i++)
//		{
//			pq.push({ vc[x][i].second, vc[x][i].first });
//		}
//	}
//
//	printf("%d", ans);
//
//	return 0;
//
//}

//ũ�罺Į
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//struct Edge { int from,to, cost; };
//int arr[100001] = { 0 };
//
//
//
//
//int Find(int x)
//{
//	if (x == arr[x]) return x;
//	return  arr[x] = Find(arr[x]);
//}
//
//void Union(int x, int y)
//{
//	x = Find(x);
//	y = Find(y);
//	arr[y] = x;
//}
//
//bool cmp(Edge a, Edge b)
//{
//	return a.cost < b.cost;
//
//}
//int main()
//{
//	int V, E;
//	scanf("%d %d", &V, &E);
//
//	vector<Edge> edge(E);
//	for (int i = 1; i <= V; i++)
//		arr[i] = i;
//
//	for (int i = 0; i < E; i++)
//		scanf("%d %d %d ", &edge[i].from, &edge[i].to, &edge[i].cost);
//	sort(edge.begin(), edge.end(), cmp);
//	int ans = 0;
//
//	for (int i = 0; i < E; i++)
//	{
//		int x = Find(edge[i].from);
//		int y = Find(edge[i].to);
//
//		if (x!= y)
//		{
//			ans += edge[i].cost;
//			Union(x, y);
//		}
//	}
//	
//	printf("%d", ans);
//}



#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#define INF 999999999
using namespace std;
int arr[20001];

struct Edge { int to, cost; };

int main()
{
	int V, E,S;
	scanf("%d %d", &V, &E);
	scanf("%d", &S);
	for (int i = 1; i <= V; i++)
		arr[i] = INF;

	vector <Edge> vc[20001];

	for (int i = 0; i < E; i++)
	{
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c);
		vc[a].push_back({ b, c});
	}
	arr[S] = 0;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < vc[S].size(); i++)
	{
		pq.push({vc[S][i].cost,vc[S][i].to });
	}



	while (pq.size())
	{
		pair<int, int>pr = pq.top();
		pq.pop();
		if (arr[pr.second] > pr.first)
		{
			arr[pr.second] = pr.first;
			int k = pr.second;
			for (int i = 0; i < vc[k].size(); i++)
			{
				pq.push({ arr[k] + vc[k][i].cost,vc[k][i].to });
			}
		}
	}



	for (int i = 1; i <= V; i++)
	{
		if (arr[i] == INF)
		{
			printf("INF\n");
		}
		else
			printf("%d\n", arr[i]);
	}

}