#include<iostream>
#include<vector>
#include<algorithm>
#define max(a,b) ((a)>(b))?a:b
using namespace std;
int N, M, K;
bool visit[301];
int D[301][301];
bool cmp(pair<int, int> const&a, pair<int, int> const&b)
{
	if (a.first < b.first)
		return 1;
	else
	{
		if (a.first == b.first)
		{
			if (a.second > b.second)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
}


int main()
{
	scanf("%d %d %d", &N, &M, &K);
	vector<pair<int, int >> in[301];
	for (int i = 0; i < K; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (b > a)
		{
			in[a].push_back(make_pair(b, c));
			visit[a] = 1;
		}
	}

	for (int i = 1; i <= N; i++)
		if (visit[i])
			sort(in[i].begin(), in[i].end(), cmp);

	for (int i = 1; i <= N; i++)
	{
		bool vi[301] = { 0 };
		for (int k = 0; k < in[i].size(); k++)
		{
			pair<int, int> p = in[i][k];
			if (!vi[p.first])
			{
				for (int m = 1; m <= M; m++)
				{
					if(D[i][m - 1]||(i==1&&m==2))
					D[p.first][m]= max(D[p.first][m], D[i][m-1] + p.second);
				}
				vi[p.first] = 1;
			}
		}
	}

	int max = 0;
	for (int i = 0; i <= M; i++)
		max = max(max, D[N][i]);
	printf("%d\n",max);


}