#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct st
{

	int start, end, cost;
	
	st() {
	}
	st(int a, int b, int c) {
		start = a;
		end = b;
		cost = c;
	}
	bool operator<(const st &other)const
	{
		return cost > other.cost;
	}

};
int main()
{
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);
	vector<pair<int, int>> ve[1001];

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		ve[a].push_back({ b,c });
		ve[b].push_back({ a,c });
	}

	bool visit[1001] = { 0 };
	priority_queue<st> q;
	visit[1] = 1;
	for (int i = 0; i < ve[1].size(); i++)
		q.push(st(1, ve[1][i].first, ve[1][i].second));
	int ans = 0;
	for (int i = 1; i < N; i++)
	{
		st tmp;
		while (!q.empty())
		{
			tmp = q.top();
			q.pop();
			if (visit[tmp.end] == false)
				break;
		}
		ans += tmp.cost;
		visit[tmp.end] = 1;
		for (int i = 0; i < ve[tmp.end].size(); i++)
		{
			q.push(st(tmp.end, ve[tmp.end][i].first, ve[tmp.end][i].second));
		}
	}
	printf("%d\n", ans);

	return 0;



}


//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//struct st
//{
//	int s, e, d;
//	st() {
//		s = 0; e = 0; d = 0;
//	}
//	st(int a, int b,int  c) {
//		s = a;
//		e = b;
//		d = c;
//	}
//
//	bool operator <(const st& other)const
//	{
//		return d > other.d;
//	}
//
//
//};
//
//
//
//bool cmp(const pair<int, int> &a, const pair<int, int> &b)
//{
//	if (a.second > b.second)
//		return 0;
//	else if (a.second < b.second)
//		return 1;
//	else
//	{
//		if (a.first > b.first)
//			return 0;
//		else
//			return 1;
//	}
//}
//bool visit[1001];
//int main()
//{
//	int N, M;
//	scanf("%d %d", &N, &M);
//	vector<pair<int,int> >in[1001];
//	for (int i = 0; i < M; i++)
//	{
//		int a, b, c;
//		scanf("%d %d %d", &a, &b, &c);
//		in[a].push_back({ b,c });
//		in[b].push_back({ a,c });
//	}
//	visit[1] = 1;
//	priority_queue<st> q;
//
//	for (int i = 0; i < in[1].size(); i++)
//		q.push(st(1, in[1][i].first, in[1][i].second));
//
//	int ans = 0;
//	for (int i = 0; i<N - 1; i++) 
//	{
//		st e;
//		while (!q.empty()) 
//		{
//			e = q.top();
//			q.pop();
//			if (visit[e.e] == false) 
//			{
//				break;
//			}
//		}
//		visit[e.e] = true;
//		ans += e.d;
//		int x = e.e;
//		for (int i = 0; i<in[x].size(); i++) 
//		{
//			q.push(st(x, in[x][i].first, in[x][i].second));
//		}
//	}
//	printf("%d\n", ans);
//	return 0;
//
//
//
//
//
//}


//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//struct st
//{
//	int s, e, d;
//	st() {
//		s = 0; e = 0; d = 0;
//	}
//	st(int a, int b,int  c) {
//		s = a;
//		e = b;
//		d = c;
//	}
//
//	bool operator <(const st& other)const
//	{
//		return d > other.d;
//	}
//
//
//};
//
//
//
//bool cmp(const pair<int, int> &a, const pair<int, int> &b)
//{
//	if (a.second > b.second)
//		return 0;
//	else if (a.second < b.second)
//		return 1;
//	else
//	{
//		if (a.first > b.first)
//			return 0;
//		else
//			return 1;
//	}
//}
//bool visit[1001];
//int main()
//{
//	int N, M;
//	scanf("%d %d", &N, &M);
//	vector<pair<int,int> >in[1001];
//	for (int i = 0; i < M; i++)
//	{
//		int a, b, c;
//		scanf("%d %d %d", &a, &b, &c);
//		in[a].push_back({ b,c });
//		in[b].push_back({ a,c });
//	}
//	visit[1] = 1;
//	priority_queue<st> q;
//
//	for (int i = 0; i < in[1].size(); i++)
//		q.push(st(1, in[1][i].first, in[1][i].second));
//
//	int ans = 0;
//	for (int i = 0; i<N - 1; i++) 
//	{
//		st e;
//		while (!q.empty()) 
//		{
//			e = q.top();
//			q.pop();
//			if (visit[e.e] == false) 
//			{
//				break;
//			}
//		}
//		visit[e.e] = true;
//		ans += e.d;
//		int x = e.e;
//		for (int i = 0; i<in[x].size(); i++) 
//		{
//			q.push(st(x, in[x][i].first, in[x][i].second));
//		}
//	}
//	printf("%d\n", ans);
//	return 0;
//
//
//
//
//
//}