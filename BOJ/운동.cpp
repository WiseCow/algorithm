#include<cstdio>
#define inf 987654321
#define min(a,b) ((a)<(b))?(a):(b)
int D[401][401];

int main()
{
	int v, e;
	scanf("%d %d ", &v, &e);

	for (int i = 0; i <= v; i++)
		for (int j = 0; j <= v; j++)
			D[i][j] = inf;


	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		D[a][b] = c;
	}

	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			for (int k = 1; k <= v; k++)
			{
				if (D[j][k]>D[j][i] + D[i][k])
					D[j][k] = D[j][i] + D[i][k];
			}
	
	int minn = inf;
	for (int i = 1; i <= v; i++)
		minn = min(minn, D[i][i]);

	if (minn == inf)
		printf("-1");
	else
		printf("%d", minn);
}