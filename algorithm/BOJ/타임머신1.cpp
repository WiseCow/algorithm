#include<iostream>
#include<vector>
using namespace std;
struct Edge
{
	int to, from, cost;
	Edge(int a, int b, int c) { from = a; to = b; cost = c; }
};
int N, M,dist[501];

int main()
{
	scanf("%d %d", &N, &M);
	vector<Edge> in;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		in.push_back(Edge(a,b,c ));
	}
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;
	bool chk = 0;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int from = in[j].from;
			int to = in[j].to;
			int cost = in[j].cost;

			if (dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
				if (i == N - 1)
					chk = 1;
			}
		}
	}

	if (chk == 1)
		printf("-1");
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (dist[i] == 0x3f3f3f3f)
				printf("-1\n");
			else
				printf("%d\n", dist[i]);
		}



	}


}