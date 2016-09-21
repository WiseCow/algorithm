#include<cstdio>
int main()
{
	int V, E;
	scanf("%d %d", &V, &E);
	int D[401][401];
	for (int i = 0; i <= V; i++)
		for (int j = 0; j <= V; j++)
			D[i][j] = 987654321;

	for (int i = 1; i <= E; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		D[a][b] = c;
	}
	
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			for (int k = 1; k <= V; k++)
				if (D[j][k] > D[j][i] + D[i][k])
					D[j][k] = D[j][i] + D[i][k];

	int maxx=987654321;
	for (int i = 1; i <= V; i++)
		if (maxx > D[i][i])
			maxx=D[i][i];

	if (maxx != 987654321)
		printf("%d", maxx);
	else
		printf("-1");
}