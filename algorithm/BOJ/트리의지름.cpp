#include<iostream>
#include<vector>
#define MAX(a,b) ((a)>(b))?a:b
using namespace std;
int n;
vector<pair<int, int>> vc[10001];

int BFS(int now, bool chk)
{
	if (chk == 0)
	{
		int k = 0;
		for (int i = 0; i < vc[now].size(); i++)
		{
			k = MAX(k,BFS(vc[now][i].first, 0) + vc[now][i].second);
		}
		return k;
	}
	else
	{
		int k = 0, k1 = 0;
		for (int i = 0; i < vc[now].size(); i++)
		{
			int t = BFS(vc[now][i].first, 0) + vc[now][i].second;
			if (k < t)
			{
				k1 = k;
				k = t;

			}
			else
			{
				if (k1 < t)
					k1 = t;
			}
		}
		return k+k1;
	}

}
int main()
{
	scanf("%d", &n);


	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vc[a].push_back({ b,c });

	}
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		max = MAX(max, BFS(i, 1));
	}
	printf("%d", max);
}
