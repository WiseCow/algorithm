//#include <cstdio>
//
//int d[30][30];
//int a[30][30];
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			scanf("%d", &d[i][j]);
//			a[i][j] = 1;
//		}
//	}
//
//	bool fail = false;
//
//	for (int k = 1; k <= n; k++)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= n; j++)
//			{
//				if (d[i][j] > d[i][k] + d[k][j])
//				{
//					fail = true;
//				}
//			}
//		}
//	}
//	if (!fail)
//	{
//		for (int k = 1; k <= n; k++)
//		{
//			for (int i = 1; i <= n; i++)
//			{
//				for (int j = 1; j <= n; j++)
//				{
//					if (k != i && k != j && d[i][j] == d[i][k] + d[k][j])
//					{
//						a[i][j] = 0;
//					}
//				}
//			}
//		}
//		for (int i = 1; i <= n; i++) a[i][i] = 0;
//
//		int ret = 0;
//
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j < i; j++)
//			{
//				if (a[i][j] == 1) ret += d[i][j];
//			}
//		}
//		printf("%d\n", ret);
//	}
//	else
//	{
//		printf("-1\n");
//	}
//
//	return 0;
//}

#include<cstdio>
int arr[21][21];
bool D[21][21];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &arr[i][j]);
			if(i!=j)
			D[i][j] = 1;
		}
	bool chk = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++)
				if (arr[j][k] > arr[j][i] + arr[i][k])
					chk = 1;
	if (!chk)
	{
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				for (int k = 1; k <= N; k++)
					if (i != j&&i != k&&arr[j][k] == arr[j][i] + arr[i][k])
						D[j][k] = 0;
		int res = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (D[i][j])res += arr[i][j];
		printf("%d", res/2);
	}
	else
		printf("-1");
	return 0;
}