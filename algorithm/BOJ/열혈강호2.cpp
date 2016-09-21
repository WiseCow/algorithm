//#include<iostream>
//#include<queue>
//#include<vector>
//#define min(a,b) a<b?a:b
//using namespace std;
//int capacity[2010][2010], flow[2010][2010];
//int main()
//{
//	int N, M;
//	scanf("%d %d", &N, &M);
//	vector<int> graph[2010];
//	for (int i = 1; i <= N; i++)
//	{
//		graph[0].push_back(i);
//		graph[i].push_back(0);
//		capacity[0][i] = 2;
//	}
//
//	for (int i = 1+N; i <= N+M; i++)
//	{
//		graph[i].push_back(N+M+1);
//		graph[N+M+1].push_back(i);
//		capacity[i][N+M+1] = 1;
//	}
//
//	for (int itr = 1; itr <= N; itr++)
//	{
//		int a, b;
//		scanf("%d", &a);
//		for (int i = 0; i < a; i++)
//		{
//			scanf("%d", &b);
//			graph[itr].push_back(N +b);
//			graph[N +b].push_back(itr);
//			capacity[itr][N + b] = 1;
//		}
//	}
//
//	int src = 0, sink = N + M + 1, total = 0;
//	while (1)
//	{
//		queue<int> q;
//		q.push(src);
//		int parent[2010] = { 0 };
//		while (q.size() && parent[sink] == 0)
//		{
//			int here = q.front(); q.pop();
//			for (int i = 0; i < graph[here].size(); i++)
//			{
//				int there = graph[here][i];
//				int capa = capacity[here][there] - flow[here][there];
//				if (capa > 0 && parent[there] == 0)
//				{
//					q.push(there);
//					parent[there] = here;
//				}
//			}
//		}
//		if (parent[sink] == 0) break;
//		int amount = 987654321;
//		for (int p = sink; p != 0; p = parent[p])
//		{
//			amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
//		}
//
//		for (int p = sink; p != 0; p = parent[p])
//		{
//			flow[parent[p]][p]+= amount;
//			flow[p][parent[p]]-= amount;
//
//		}
//		total += amount;
//	}
//	printf("%d", total);
//}
//
//#include<cstdio>
//#include<vector>
//#include<string.h>
//#define A 1001 // 직원 수 최대
//#define B 1001 // 일 수 최대
//using namespace std;
//vector<int> G[A]; // 직원
//int rev[B] = { 0, }; // 일
//bool chk[B]; // 재탐색 방지 배열
//int dfs(int i) {
//	for (int j = 0; j < G[i].size(); j++) {
//		int no = G[i][j]; // 체크할 일 번호
//		if (chk[no]) { // 재탐색 방지
//			chk[no] = false;
//			if (rev[no] == 0 || (rev[no] != i&&dfs(rev[no]))) { // 업무에 접근한 사람이 없거나, 내가 접근하지 않은 일 중 양보 받을수 있는것
//				rev[no] = i;
//				return 1;
//			}
//		}
//	}
//	return 0;
//}
//int main() {
//	int N, M, cnt = 0, a, b; // 사람 수, 일 수, 결과, input_data
//	scanf("%d %d", &N, &M);
//	for (int i = 1; i <= N; i++) {
//		scanf("%d", &a); // 가능한 일 수
//		for (int itr = 0; itr < a; itr++) {
//			scanf("%d", &b); // 일 번호
//			G[i].push_back(b); // 사람 i에게 b할당
//		}
//	}
//	for (int i = 1; i <= N; i++) {
//		memset(chk, true, sizeof(chk));
//		cnt += dfs(i) + dfs(i);
//	}
//	printf("%d\n", cnt);
//	return 0;
//}



#include<iostream>
#include<vector>
#include<cstring>
#define MAX_V 1010
using namespace std;
vector<int> vec[MAX_V];
bool visit[MAX_V];
int insert[MAX_V];
bool sol(int now)
{
	if (visit[now])
		return 0;
	visit[now] = 1;
	for (int i = 0; i < vec[now].size(); i++)
	{
		int next = vec[now][i];

		if (!insert[next] || sol(insert[next]))
		{
			insert[next] = now;
			return 1;
		}
	}
	return 0;
}


int main()
{
	int N, M,res=0;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		int a, b;
		scanf("%d ", &a);
		while (a--)
		{
			scanf("%d", &b);
			vec[i].push_back(b);
		}
	}
	for (int j = 0; j < 2;j++)
	for (int i = 1; i <= N; i++)
	{
		memset(visit, 0, sizeof(visit));
		res += sol(i);
	}

	printf("%d", res);
}