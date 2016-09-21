#include<cstdio>
struct Edge
{
	int from;
	int to;
	int cost;
	Edge()
	{}
};
int main()
{
	int T;
	scanf("%d", &T);
	for (int itr = 0; itr < T; itr++)
	{
		int N, M, W;
		scanf("%d %d %d", &N, &M, &W);
		Edge in[5300];
		int a, b, c;
		for (int i = 0; i < M*2; i+=2)
		{
			scanf("%d %d %d", &a, &b, &c);
			in[i].from = a;
			in[i].to = b;
			in[i].cost = c;
			in[i+1].from = b;
			in[i+1].to = a;
			in[i+1].cost = c;
		}
		for (int i = M*2; i < M*2+W; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			in[i].from = a;
			in[i].to = b;
			in[i].cost = -c;
		}
		int D[501] = { 0 };
		for (int i = 0; i <= N; i++)
			D[i] = 987654321;
		bool chk = 0;
		D[1] = 0;
		for (int i = 1; i < N; i++)
			for (int j = 0; j < M*2+W; j++)
				if (D[in[j].to]>D[in[j].from] + in[j].cost)
				{
					D[in[j].to] = D[in[j].from] + in[j].cost;
					if (i == N - 1)
						chk = 1;
				}
		if (!chk)
			printf("NO\n");
		else
			printf("YES\n");
	}
}