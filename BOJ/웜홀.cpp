#include<iostream>
#include<vector>
#define inf 987654321
#define min(a,b) ((a)<(b))?(a):(b)
using namespace std;
struct node
{
	int from;
	int to;
	int cost;
	node() {}
	node(int a, int b, int c) { from = a; to = b; cost = c; }
};
int main()
{
	int T;
	scanf("%d", &T);

	for (int itr = 0; itr < T; itr++)
	{
		int D[501] = { 0 };
		int N, M, W;
		scanf("%d %d %d", &N, &M, &W);
		for (int i = 2; i <= N; i++)
				D[i] = inf;


		vector<node> in;
		for (int i = 1; i <= M; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			in.push_back(node(a, b, c));
			in.push_back(node(b, a, c));
		}
		for (int i = 1; i <= W; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			in.push_back(node(a, b, -c));

		}

		bool chk = 0;
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j < in.size(); j++)
			{
				int from = in[j].from;
				int to = in[j].to;
				int cost = in[j].cost;
				if (D[to] > D[from] + cost)
				{
					D[to] = D[from] + cost;
					if(i==N-1)
					{
						chk = 1;
					}
				}
			}
		}

		if (chk)
			printf("YES\n");
		else
			printf("NO\n");
	
	}
}