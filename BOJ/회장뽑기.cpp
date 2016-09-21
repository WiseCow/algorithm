#include<iostream>
#define max(a,b) ((a)>(b))?a:b
#define min(a,b) ((a)<(b))?a:b
using namespace std;
int in[60][60], D[60][60];
int cnt = 0;
int M;
int main()
{
	scanf("%d", &M);

	while (1)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == -1 && b == -1)
			break;
		in[a][b] = 1;
		in[b][a] = 1;
	}
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= M; j++)
		{
			if (!in[i][j])
				D[i][j] = 1000;
			else
				D[i][j] = in[i][j];
		}


	for (int k = 2; k < M; ++k)
	{
		for (int i = 1; i <= M; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				if (D[i][j] > D[i][k] + D[k][j])
				{
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= M; i++)
		D[i][i] = 0;



	int arr[60] = { 0 };
	int mc = 0;
	int minn = 1000;

	for (int i = 1; i <= M; i++)
	{
		int maxx = 0;
		for (int j = 1; j <= M; j++)
			if(D[i][j]!=1000&&D[i][j]!=0)
				maxx = max(maxx, D[i][j]);

		if (maxx != 0)
		{
			arr[i] = maxx;
			if (minn > maxx)
			{
				minn = maxx;
				mc = 1;
			}
			else if (minn == maxx)
			{
				mc++;
			}
		}
		else
			arr[i] = 1000;
	}


	printf("%d %d\n",minn,mc);
	for (int i = 1; i <= M; i++)
	{
		if (arr[i] == minn)
			printf("%d ", i);
	}

	printf("\n");
	return 0;
}