#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int N, M, K;
int match[1001];
bool visit[1001];
vector<int> edge[1001];
char buf[1 << 18];
int idx, nidx;
static inline char read()
{
	if (idx == nidx)
	{
		nidx = fread(buf, 1, 1 << 18, stdin);
		idx = 0;
	}
	return buf[idx++];
}
static inline int readInt()
{
	int sum = 0;
	char now = read();
	while (now == ' ' || now == '\n')
		now = read();

	while (now != ' '&&now != '\n')
	{
		sum *= 10;
		sum += now - '0';
		now = read();
	}
	return sum;
}
bool dfs(int now)
{
	for (int i = 0; i < edge[now].size(); i++)
	{
		int there = edge[now][i];
		if (!visit[there])
		{
			visit[there] = 1;
			if (match[there] == 0 || dfs(match[there]))
			{
				match[there] = now;
				return true;
			}
		}

	}
	return false;
}
int main()
{
	N = readInt();
	M = readInt();
	K = readInt();
	for (int i = 1; i <= N; i++)
	{
		int a, b;
		a = readInt();
		for (int j = 0; j < a; j++)
		{
			b = readInt();
			edge[i].push_back(b);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		memset(visit, 0, sizeof(visit));
		if (dfs(i))
			cnt++;
	}
	for (int i = 1,t=0; i <= N&&t<K; i++)
	{
		memset(visit, 0, sizeof(visit));
		if (dfs(i))
		{
			cnt++;
			t++;
		}
	}
	printf("%d", cnt);
}



//#include<cstdio>
//#include<cstring>
//#include<queue>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int N, M, K,source,sink;
//int cap[2003][2003],flow[2003][2003], par[2003];
//bool visit[2003];
//vector<int>edge[2003];
//int dfs()
//{
//	queue<int>q;
//	q.push(source);
//	visit[source] = 1;
//	while (q.size() && !visit[sink])
//	{
//		int now = q.front();
//		q.pop();
//		for (int i = 0; i < edge[now].size(); i++)
//		{
//			int there = edge[now][i];
//			if (cap[now][there]-flow[now][there]>0&&!visit[there])
//			{
//				par[there] = now;
//				q.push(there);
//				visit[there] = 1;
//			}
//		}
//	}
//	if (!visit[sink])
//		return 0;
//	int amount = 0x3f3f3f3f;
//	int tmp = sink;
//	while (par[tmp] != -1)
//	{
//		amount = min(amount, cap[par[tmp]][tmp] - flow[par[tmp]][tmp]);
//		tmp = par[tmp];
//	}	
//	tmp = sink;
//	while (par[tmp] != -1)
//	{
//		flow[par[tmp]][tmp] += amount;
//		flow[tmp][par[tmp]] -= amount;
//		tmp = par[tmp];
//	}
//	return amount;
//}
//
//int sol()
//{
//	int ret = 0;
//	while (1)
//	{
//		memset(par, -1, sizeof(par));
//		memset(visit, 0, sizeof(visit));
//		int f = dfs();
//		if (f == 0)
//			break;
//		ret += f;
//	}
//	return ret;
//}
//
//int main()
//{
//	scanf("%d%d%d", &N, &M, &K);
//	for (int i = 1; i <= N; i++)
//	{
//		edge[0].push_back(i);
//		edge[2002].push_back(i);
//		cap[0][i] = 1;
//		cap[2002][i] = 1;
//		edge[i].push_back(0);
//		edge[i].push_back(2002);
//	}
//	edge[0].push_back(2002);
//	cap[0][2002] = K;
//	edge[2002].push_back(0);
//	for (int i = N + 1; i <= N + M; i++)
//	{
//		edge[i].push_back(N + M + 1);
//		edge[N + M + 1].push_back(i);
//		cap[i][N + M + 1] = 1;
//	}
//	for (int i = 1; i <= N; i++)
//	{
//		int t;
//		scanf("%d", &t);
//		for (int j = 0; j < t; j++)
//		{
//			int k;
//			scanf("%d", &k);
//			edge[i].push_back(k+N);
//			edge[k + N].push_back(i);
//			cap[i][k + N] = 1;
//		}
//	}
//	source = 0;
//	sink = N + M + 1;
//	printf("%d", sol());
//}