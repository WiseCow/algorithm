#include<cstdio>
using namespace std;
int K, C, M, N;
int main()
{
	scanf("%d%d", &K, &C);
	for (int itr = 0; itr < C; itr++)
	{
		scanf("%d%d", &M, &N);

		if (M < N)
		{
			if (N - 1 < K - N + M+1)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (M > N)
		{
			if (M - 1 <= K - M + N + 1)
				printf("1\n");
			else
				printf("0\n");
		}
		else
			printf("1\n");
	}
}
//
//#include<iostream>
//using namespace std;
//
//int main() {
//	int k, c;
//	scanf("%d%d", &k, &c);
//	int a, b;
//	for (int i = 0; i < c; i++)
//	{
//		scanf("%d%d", &a, &b);
//
//		if (a > b) {
//
//			if ((a - 1) <= b + (k - a) + 1)
//				printf("1\n");
//			else
//				printf("0\n");
//		}
//		else if (a < b)
//		{
//			if ((b - 1) < a + (k - b) + 1)
//				printf("1\n");
//			else printf("0\n");
//		}
//		else
//			printf("1\n");
//	}
//	return 0;
//}