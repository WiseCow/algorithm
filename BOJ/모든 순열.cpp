#include<iostream>
using namespace std;
int N;

void dfs(int now, int jari,int map[10],bool visit[10])
{
	if (jari == N + 1)
	{
		for (int i = 1; i <= N; i++)
		{
				printf("%d ", map[i]);
		}
				printf("\n");
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			if (!visit[i])
			{
				map[jari] = i;
				visit[i] = 1;
				dfs(i, jari+1, map,visit);
				map[jari] = 0;
				visit[i] = 0;
			}
		}
	}
}
int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		int map[10] = { 0 };
		bool visit[10] = { 0 };
		map[1] = i;
		visit[i] = 1;
		dfs(i, 2, map,visit);
		map[1] = 0;
		visit[i] = 0;
	}
	return 0;
}