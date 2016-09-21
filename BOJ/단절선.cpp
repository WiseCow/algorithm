#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>vc[100001];
vector<pair<int, int>> ans;
int V, E,nn,map[100001];
char buf[1 << 19];
int kidx, knidx;
static inline char read()
{
	if (kidx == knidx)
	{
		knidx = fread(buf, 1, 1 << 19, stdin);
		kidx = 0;
	}
	return buf[kidx++];
}
static inline int readInt()
{
	int sum = 0;
	char now = read();
	while (now == ' ' || now == '\n'&&now != EOF)
		now = read();

	while (now != ' '&&now != '\n'&&now != EOF)
	{
		sum *= 10;
		sum += now - '0';
		now = read();
	}
	return sum;
}
int dfs(int idx, int pre)
{
	map[idx] = nn++;
	int ret = map[idx];
	for (int i = 0; i < vc[idx].size(); i++)
	{
		int nidx = vc[idx][i];
		if (nidx == pre)
			continue;
		if (map[nidx] == -1)
		{
			int sub = dfs(nidx, idx);
			if (sub > map[idx])
				ans.push_back({ idx,nidx });
			ret = min(ret, sub);
		}
		else
			ret = min(ret, map[nidx]);
	}
	return ret;
}
int main()
{
	V = readInt();
	E = readInt();
	for (int i = 0; i < E; i++)
	{
		int a, b;
		a = readInt();
		b = readInt();
		vc[a].push_back(b);
		vc[b].push_back(a);
	}
	memset(map, -1, sizeof(map));
	for (int i = 1; i <= V; i++)
		if (map[i] == -1)
			dfs(i, 0);

	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i].first > ans[i].second)
		{
			ans[i].first ^= ans[i].second;
			ans[i].second ^= ans[i].first;
			ans[i].first ^= ans[i].second;
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d %d\n", ans[i].first, ans[i].second);

}