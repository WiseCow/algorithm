#include<cstdio>
#include<vector>
using namespace std;
vector<int> in[101];
int res[101];
bool sol(int now,bool visit[101])
{
	if (visit[now])
		return 0;
	visit[now] = 1;
	for (int i = 0; i < in[now].size(); i++)
	{
		int k = in[now][i];
		if (!res[k] || sol(res[k], visit))
		{
			res[k] = now;
			return 1;
		}
	}
	return 0;
}




int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		int c,d;
		scanf("%d %d", &c, &d);
		in[c].push_back(d);
	}

	int res=0;
	for (int i = 1; i <= N; i++)
	{
		bool visit[101] = { 0 };
		if (sol(i,visit))
			res++;
	}
	printf("%d\n", res);
	return 0;
}