//#include<iostream>
//using namespace std;
//int arr[1000][1000];
//long long dist[1000][1000];
//long long nowd[1000][1000];
//int main()
//{
//	int N, M;
//	scanf("%d %d", &N, &M);
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			scanf("%d", &arr[i][j]);
//
//	dist[0][0] = arr[0][0];
//	for (int j = 1; j < M; j++)
//		dist[0][j] = arr[0][j]+dist[0][j-1];
//	for (int i = 1; i < N; i++)//현재라인
//	{
//
//		for (int ni = 0; ni < 1; ni++)
//		{
//			int dd = 0;
//			for (int nj = ni; nj < M; nj++)
//			{
//				dd += arr[i][nj];
//				nowd[ni][nj] = dd;
//				nowd[nj][ni] = dd;
//			}
//		}
//		for (int ni = 1; ni < M; ni++)
//		{
//			for (int nj = ni; nj < M; nj++)
//			{
//				nowd[ni][nj] = nowd[ni - 1][nj] - arr[i][ni-1];
//				nowd[nj][ni] = nowd[ni - 1][nj] - arr[i][ni - 1];
//			}
//		
//		}
//		for (int q = 0; q < M; q++)
//		{
//			for (int w = 0; w < M; w++)
//			{
//				nowd[q][w] += dist[i-1][q];
//			}
//		}
//
//
//
//		for (int j = 0; j < M; j++)//현재 위치
//		{
//
//			long long max = 0;
//			for (int k = 0; k < M; k++)//윗줄 위치
//			{
//				if (nowd[k][j]>max)
//				{
//					max = nowd[k][j];
//				}
//			}
//			dist[i][j] = max;
//		}
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			printf("%d\t", dist[i][j]);
//
//		}
//		printf("\n");
//	}
//	printf("%lld\n", dist[N - 1][M - 1]);
//
//}

//https://www.acmicpc.net/problem/2169
#include <iostream>
long long input[1001][1001] = { 0, };
long long output[1001][1001] = { 0, };
long long output_temp[1001] = { 0, };



int main()
{
	int i, j;
	int temp = 0;
	int n, m;
	scanf("%d %d", &n,&m);


	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{

			scanf("%lld", &input[i][j]);
		}
	}



	for (j = 1; j <= m; j++)
	{


		temp += input[1][j];
		output[1][j] = temp;
	}

	temp = 0;



	for (i = 2; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (j == 1)
			{
				output[i][j] = output[i - 1][j] + input[i][j];
			}
			else
			{
				if (output[i][j - 1]>output[i - 1][j])
				{
					output[i][j] = input[i][j] + output[i][j - 1];
				}
				else
				{
					output[i][j] = input[i][j] + output[i - 1][j];
				}

			}
		}

		for (j = m; j >= 1; j--)
		{
			if (j == m)
			{
				output_temp[j] = output[i - 1][j] + input[i][j];

				if (output_temp[j]>output[i][j])
				{
					output[i][j] = output_temp[j];
				}
			}

			else
			{
				if (output_temp[j + 1]>output[i - 1][j])
				{
					output_temp[j] = output_temp[j + 1] + input[i][j];

					if (output_temp[j]>output[i][j])
					{
						output[i][j] = output_temp[j];
					}
				}
				else
				{

					output_temp[j] = input[i][j] + output[i - 1][j];

					if (output_temp[j]>output[i][j])
					{
						output[i][j] = output_temp[j];
					}

				}
			}

		}

	}
	printf("%lld\n", output[n][m]);

	return 0;
}