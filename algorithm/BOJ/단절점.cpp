#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<int>edge[100001];
int discovered[100001],N,M,dis_cnt;
bool ans[100001];

int dfs(int now, bool root)
{
	discovered[now] = dis_cnt++;
	int child = 0;
	int ret = discovered[now];
	for (int i = 0; i < edge[now].size(); i++)
	{
		int there = edge[now][i];
		if (discovered[there] == -1)
		{
			child++;
			int subtree = dfs(there, 0);
			if (!root&&subtree >= discovered[now])
				ans[now] = true;
		}
	}
}
int main()
{
	memset(discovered, -1, sizeof(discovered));

	scanf("%d%d", &N, &M);
	for (int i = 0; i <= M; i++)
	{
		int a, b;
		edge[a].push_back(b);
		edge[b].push_back(a);

	}
	for (int i = 1; i <= N; i++) {
		if (discovered[i] == -1)
			dfs(i, 1);
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (ans[i])
			cnt++;
	}
	for (int i = 1; i <= N;i++)
		if(ans[i])

}


//#include <iostream>
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//#define MAXV 10010
//int V, E, counter = 0, discovered[MAXV];
//bool isCutVertex[MAXV];
//vector<int> graph[MAXV];
//
//int dfs(int A, bool isRoot) {
//	discovered[A] = ++counter;
//	int ret = discovered[A];
//
//	int child = 0;
//	for (int i = 0; i< (int)graph[A].size(); i++) {
//		int next = graph[A][i];
//		if (!discovered[next]) {
//			child++;
//			int low = dfs(next, false);
//			if (!isRoot && low >= discovered[A])
//				isCutVertex[A] = true;
//			ret = min(ret, low);
//		}
//		else {
//			ret = min(ret, discovered[next]);
//		}
//	}
//
//	if (isRoot)
//		isCutVertex[A] = (child >= 2);
//	return ret;
//}
//
//int main() {
//	scanf("%d%d", &V, &E);
//	for (int i = 1; i <= E; i++) {
//		int a, b;
//		scanf("%d%d", &a, &b);
//		graph[a].push_back(b);
//		graph[b].push_back(a);
//	}
//
//	for (int i = 1; i <= V; i++) {
//		if (!discovered[i])
//			dfs(i, true);
//	}
//
//	int cnt = 0;
//	for (int i = 1; i <= V; i++) {
//		if (isCutVertex[i])
//			cnt++;
//	}
//	printf("%d\n", cnt);
//	for (int i = 1; i <= V; i++) {
//		if (isCutVertex[i])
//			printf("%d ", i);
//	}
//	return 0;
//}