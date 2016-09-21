#include<cstdio>
using namespace std;
int N, K, S;
int vc[401][401];
int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		vc[a][b] = -1;
		vc[b][a] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
				if (vc[j][i] !=0 && vc[j][i] == vc[i][k])
				{
					vc[j][k] = vc[j][i];
				}
		}
	}
	scanf("%d", &S);
	for (int i = 0; i < S; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", vc[a][b]);
	}
	return 0;
}