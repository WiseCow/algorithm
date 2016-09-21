#include<iostream>
#include<vector>
#include<queue>
#define min(a,b) (a)>(b)?(b):(a)
#define MAX_V 210
using namespace std;
const int INF = 987654321;
int n, m;
struct Edge { int target, cost; };
vector <int> graph[MAX_V];
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		graph[0].push_back(i);
		graph[i].push_back(0);
		capacity[0][i] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		graph[n + i].push_back(n + m + 1);
		graph[n + m + 1].push_back(n + i);
		capacity[n + i][n + m + 1] = 1;
	}


	int a, b;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		for (int j = 0; j < a; j++)
		{
			scanf("%d", &b);
			graph[i].push_back(n + b);
			graph[n + b].push_back(i);
			capacity[i][n + b] = 1;
		}
	}
	int source = 0, sink = n + m + 1, total = 0;
	while (1)
	{
		int parent[210] = { 0, };
		queue<int> q;
		parent[source] = source;
		q.push(source);
		while (!q.empty() && parent[sink] == 0)
		{
			int here = q.front();
			q.pop();
			for (int i = 0; i < graph[here].size(); i++)
			{
				int there = graph[here][i];
				int capa = capacity[here][there];
				if (capa - flow[here][there]>0 && parent[there] == 0)
				{
					q.push(there);
					parent[there] = here;
				}
			}
		}
		if (parent[sink] == 0)break;
		int amount = INF;
		for (int p = sink; p != source; p = parent[p])
			amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
		for (int p = sink; p != source; p = parent[p])
		{
			flow[p][parent[p]] -= amount;
			flow[parent[p]][p] += amount;
		}
		total += amount;

	}
	printf("%d\n", total);
	return 0;
}
//
//#include <iostream>
//#include <queue>
//#include <cstdio>
//#include <vector>
//using namespace std;
//#define SIZE 2001
//#define min(x, y) (x)< (y) ? (x): (y)
//#define INF 0x7fffffff
//struct Edge{ int target, cost; };
//vector<int> graph[SIZE];
//int flow[SIZE][SIZE];
//int capacity[SIZE][SIZE];
//int N, M;
//int main(void)
//{
//    scanf("%d%d", &N, &M);
//     
//    for (int i = 1; i <= N; i++)
//    {
//        graph[0].push_back(i);
//        graph[i].push_back(0);
//        capacity[0][i] = 1;
//    }
//    for (int i = 1; i <= M; i++)
//    {
//        graph[N + i].push_back(N + M + 1);
//        graph[N + M + 1].push_back(N + i);
//        capacity[N + i][N + M + 1] = 1;
//    }
//    int A, B;
//    for (int i = 1; i <= N; i++)
//    {
//        scanf("%d", &A);
//        for (int j = 0; j < A; j++)
//        {
//            scanf("%d", &B);
//            graph[i].push_back(N+B);
//            graph[N + B].push_back(i);
//            capacity[i][N + B] = 1;
//        }
//    }
// 
//    int source = 0, sink = N + M + 1, total = 0;
//    while (1)
//    {
//        int parent[SIZE] = { 0, };
//        queue<int> Q;
//        parent[source] = source;
//        Q.push(source);
//        while (!Q.empty() && parent[sink] == 0)
//        {
//            int here = Q.front();
//            Q.pop();
//            for (int i = 0; i < graph[here].size(); i++)
//            {
//                int there = graph[here][i];
//                int capa = capacity[here][there];
//                if (capa - flow[here][there] > 0 && parent[there] == 0)
//                {
//                    Q.push(there);
//                    parent[there] = here;
//                }
//            }
//        }
// 
//        if (parent[sink] == 0)
//            break;
//        int amount = INF;
// 
//        for (int p = sink; p != source; p = parent[p])
//            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
// 
//        for (int p = sink; p != source; p = parent[p])
//        {
//            flow[p][parent[p]] -= amount;
//            flow[parent[p]][p] += amount;
//        }
//        total += amount;
// 
//    }
//    printf("%d", total);
// 
// 
// 
//    return 0;
//}