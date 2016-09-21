#include<iostream>
#include<vector>
using namespace std;
vector<int> arr[100001];
int par[100001] = { 0 };
void find(int now, bool visit[100001])
{
	if (visit[now])
		return;
	else
	{
			visit[now] = 1;
			for (int i = 0; i < arr[now].size(); i++)
			{
				if (par[arr[now][i]] == 0)
					par[arr[now][i]] = now;
				if(!visit[arr[now][i]])
					find(arr[now][i], visit);
			}
	}
}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	bool visit[100001] = { 0 };
	find(1, visit);

	for (int i = 2; i <= N; i++)
	{
		printf("%d\n", par[i]);
	}
}