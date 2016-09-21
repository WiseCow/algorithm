#include<iostream>
#include<vector>
#define INF 987654321
using namespace std;
struct Edge { int from, to, cost; };
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int map[501];
	vector<Edge> input;
	for (int itr = 0; itr < M; itr++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		input.push_back({ a,b,c });
	}
	for (int i = 1; i <= N; i++)
		map[i] = INF;
	map[1] = 0;

	bool chk = 0;
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < input.size(); k++)
		{
			int to=input[k].to, from = input[k].from, cost = input[k].cost;
			if (map[to] > map[from] + cost)
			{
				if (i == N - 1)
					chk = 1;
				map[to] = map[from] + cost;
			}
		}
	}
	if (chk == 1)
		printf("-1");
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (map[i] == INF)
				printf("-1\n");
			else
			printf("%d\n", map[i]);
		}
	}


}