#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int N, M;
vector<int>edge[101];
bool visit[101];
int match[101];
bool dfs(int now)
{
	if (visit[now])
		return false;
	visit[now] = true;
	for (int i = 0; i < edge[now].size(); i++)
	{
		int there = edge[now][i];
		if (match[there] == -1 ||dfs(match[there]))
		{
			match[there] = now;
			return true;
		}
	}
	return false;
}
int main()
{
	memset(match, -1, sizeof(match));
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		memset(visit, 0, sizeof(visit));
		if (dfs(i))
			cnt++;
	}
	printf("%d", cnt);

}


//#include<cstdio>
//#include<cstring>
//#include<queue>
//#include<algorithm>
//using namespace std;
//int N, M,source,sink;
//int cap[300][300], flow[300][300], par[300];
//bool trip[300];
//int bfs()
//{
//	queue<int>q;
//	q.push(source);
//	while (q.size()&&!trip[sink])
//	{
//		int now = q.front();
//		q.pop();
//		for (int i = 1; i <= N + N +1; i++)
//		{
//			if (cap[now][i] - flow[now][i]>0 && !trip[i])
//			{
//				par[i] = now;
//				q.push(i);
//				trip[i] = 1;
//			}
//		}
//	}
//	int tmp = sink;
//	int amount = 2;
//	while (par[tmp] != -1)
//	{
//		amount = min(amount, cap[par[tmp]][tmp] - flow[par[tmp]][tmp]);
//		tmp = par[tmp];
//	}
//	if (amount == 2)
//		return 0;
//	tmp = sink;
//	while (par[tmp] != -1)
//	{
//		flow[par[tmp]][tmp] += amount;
//		flow[tmp][par[tmp]] -= amount;
//		tmp = par[tmp];
//	}
//	return amount;
//}
//int sol()
//{
//	int ret = 0;
//
//	while(1)
//	{
//		memset(trip, 0, sizeof(trip));
//		memset(par, -1, sizeof(par));
//		int f = bfs();
//		if (f == 0)
//			break;
//		ret += f;
//	}
//	return ret;
//}
//int main()
//{
//	scanf("%d%d", &N, &M);
//	source = 0;
//	sink = N +N+ 1;
//	for (int i = 1; i <= N; i++)
//	{
//		cap[0][i] = 1;
//	}
//	for (int i = N + 1; i <= N + N; i++)
//	{
//		cap[i][N + N + 1] = 1;
//	}
//	for (int i = 0; i < M; i++)
//	{
//		int a, b;
//		scanf("%d%d", &a, &b);
//		cap[a][b+N] += 1;
//	}
//	printf("%d", sol());
//}