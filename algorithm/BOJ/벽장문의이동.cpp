#include<iostream>
 
#define min(a,b) ((a)<(b))?a:b
using namespace std;
int N, op1, op2,tc;
int arr[21];
int D[21][21][21];
int abs(int a)
{
	return a > 0 ? a : -a;
}
int main()
{
	scanf("%d", &N);
	scanf("%d %d", &op1, &op2);
	scanf("%d", &tc);


	for (int i = 1; i <= tc; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++)
				D[i][j][k] = 987654321;


	for (int i = 1; i <= tc; i++)
	{
		scanf("%d", &arr[i]);

		if (i == 1)
		{
			if (op1 == arr[i])
			{
				D[i][arr[i]][op2] = 0;

			}
			else if (op2 == arr[i])
			{
				D[i][arr[i]][op1] = 0;
			}
			else
			{
				D[i][arr[i]][op2] = abs(arr[i] - op1);
				D[i][arr[i]][op1] = abs(arr[i] - op2);
			}

		}
		else
		{
			for (int j = 1; j <= N; j++)
			{
				if (D[i - 1][arr[i - 1]][j] != 987654321)
				{
					if (arr[i - 1] == arr[i])
					{
						D[i][arr[i]][j] = min(D[i][arr[i]][j],D[i - 1][arr[i - 1]][j]);
					}
					else if (j == arr[i])
					{
						D[i][arr[i]][arr[i - 1]] = min(D[i][arr[i]][arr[i - 1]],D[i - 1][arr[i - 1]][j]);
					}
					else
					{
						D[i][arr[i]][j] = min(D[i][arr[i]][j], D[i - 1][arr[i - 1]][j] + abs(arr[i]-arr[i-1]));
						D[i][arr[i]][arr[i - 1]] = min(D[i][arr[i]][arr[i - 1]], D[i - 1][arr[i - 1]][j] + abs(arr[i] - j));
					}
				}

			}
		}
	}
	int minn = 987654321;
	for (int i = 1; i <= N; i++)
	{
		minn = min(minn, D[tc][arr[tc]][i]);
	}
	printf("%d\n", minn);
}