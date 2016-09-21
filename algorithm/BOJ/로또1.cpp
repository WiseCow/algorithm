#include<iostream>
using namespace std;
int N;

int input[15];
void dfs(int now, int jari, int map[15], bool visit[15])
{
	if (jari == 7)
	{
		for (int i = 1; i <= 6; i++)
		{
			printf("%d ", input[map[i]]);
		}
		printf("\n");
	}
	else
	{
		for (int i = now+1; i <= N; i++)
		{
			if (!visit[i])
			{
				map[jari] = i;
				visit[i] = 1;
				dfs(i, jari + 1, map, visit);
				map[jari] = 0;
				visit[i] = 0;
			}
		}

	}








}
int main()
{
	while (1)
	{
		scanf("%d", &N);

		if (N == 0)
			return 0;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &input[i]);
		}


		for (int i = 1; i <= N; i++)
		{
			int map[15] = { 0 };
			bool visit[15] = { 0 };
			map[1] = i;
			visit[i] = 1;
			dfs(i, 2, map, visit);
			map[1] = 0;
			visit[i] = 0;
		}
		printf("\n");
	}
	return 0;
}