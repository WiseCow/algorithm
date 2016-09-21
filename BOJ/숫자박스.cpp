#include<iostream>
#define max(a,b) ((a)>(b))?a:b
using namespace std;
int D[802][401][401];
int arr[401][2];
int main()
{
	int N;
	scanf("%d", &N);
	int u = 1;
	for (int i = 1; i <= N; i++)
	{
		int a;
		scanf("%d", &a);
		if (a != 0)
			arr[u++][0] = a;
	}
	int d = 1;
	for (int i = 1; i <= N; i++)
	{
		int a;
		scanf("%d", &a);
		if (a != 0)
			arr[d++][1] = a;
	}
	u--;
	d--;
	for (int i = 2; i <= (u + d); i++)
	{
		for (int j = 1; j <i; j++)
		{
			if (((i - j) <= u)&&(j<=d))
			{
				D[i][i - j][j] = D[i - 2][i - j - 1][j - 1] + arr[i - j][0] * arr[j][1];
				D[i][i - j][j] = max(D[i][i - j][j], D[i - 1][i - j - 1][j]);
				D[i][i - j][j] = max(D[i][i - j][j], D[i - 1][i - j][j - 1]);
			}
		}
	}
	printf("%d\n", D[u + d][u][d]);
}

//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//int n, u, d, sol;
//int U[401], D[401], C[401][401][401];
//int main() {
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		int tmp;
//		scanf("%d", &tmp);
//		if (tmp != 0) U[++u] = tmp;
//	}
//	for (int i = 1; i <= n; i++) {
//		int tmp;
//		scanf("%d", &tmp);
//		if (tmp != 0) D[++d] = tmp;
//	}
//
//
//	C[1][1][1] = U[1] * D[1];
//	for (int i = 2; i <= n; i++) {
//		C[i][1][1] = U[1] * D[1];
//		for (int j = 2; j <= u && j <= i; j++)
//			C[i][j][1] = max(C[i][j - 1][1], U[j] * D[1]);
//		for (int j = 1; j <= u && j <= i - 1; j++)
//			C[i][j][1] = max(C[i][j][1], 0);
//
//		C[i][1][1] = U[1] * D[1];
//		for (int k = 2; k <= d && k <= i; k++)
//			C[i][1][k] = max(C[i][1][k - 1], U[1] * D[k]);
//		for (int k = 1; k <= d && k <= i - 1; k++)
//			C[i][1][k] = max(C[i][1][k], 0);
//	}
//	for (int i = 2; i <= n; i++) {
//		for (int j = 2; j <= u && j <= i; j++) {
//			for (int k = 2; k <= d && k <= i; k++) {
//				C[i][j][k] = C[i - 1][j - 1][k - 1] + U[j] * D[k];
//
//				if (i - 1 >= k)
//					C[i][j][k] = max(C[i][j][k], C[i - 1][j - 1][k]);
//				if (i - 1 >= j)
//					C[i][j][k] = max(C[i][j][k], C[i - 1][j][k - 1]);
//			}
//		}
//	}
//
//	sol = C[n][u][d];
//
//	printf("%d\n", sol);
//}