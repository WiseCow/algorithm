#include<iostream>
using namespace std;
int chk(int a, int b, int c)
{
	if (a >= b)
	{
		if (a >= c)
			return a;
		else if (b >= c)
			return b;
		else
			return c;
	}
	else
	{
		if (b >= c)
			return b;
		else if (c >= a)
			return c;
		else 
			return a;
	}


}



int arr[2][100001];
int dist[3][100001];
int main()
{
	int tc;
	scanf("%d", &tc);

	for (int itr = 0; itr < tc; itr++)
	{
		int col;
		scanf("%d", &col);



		for (int k = 0; k < 2; k++)
			for (int i = 1; i <= col; i++)
				scanf("%d", &arr[k][i]);

		dist[0][0] = 0;
		dist[1][0] = 0;
		dist[2][0] = 0;
		dist[0][1] = arr[0][1];
		dist[1][1] = arr[1][1];
		dist[2][1] = 0;

		for (int i = 2; i <= col; i++)
		{
			dist[0][i] = chk(dist[1][i-1],dist[2][i-1],0)+arr[0][i];
			dist[1][i] = chk(dist[0][i - 1], dist[2][i - 1], 0) + arr[1][i];
			dist[2][i] = chk(dist[0][i - 1], dist[1][i - 1], dist[2][i - 1]);
		}

		int max = 0;
		for (int i = 0; i < 3; i++)
			if (max<dist[i][col])
				max = dist[i][col];


		printf("%d\n", max);

		memset(dist, 0, sizeof(dist));
	}
}
