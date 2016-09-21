//#include<cstdio>
//#include<cstring>
//#include<time.h>
//typedef long long int ll;
//
//ll DP[500000];
//bool K[500000];
//
//ll fibo(int i)
//{
//	ll &ret = DP[i];
//	if (ret != -1)return ret;
//	ret = 0;
//	ret = fibo(i - 1) + fibo(i - 2);
//	return ret;
//}
//int main()
//{
//
//	clock_t a = clock();
//	memset(K, 1, sizeof(K));
//	clock_t b = clock();
//	for (int i = 0; i < 500000; i++)K[i] = 1;
//	clock_t c = clock();
//
//	memset(DP, -1, sizeof(DP));
//
//	printf("%d %d\n\n", (int)b - (int)a, (int)c - (int)b);
//
//	DP[0] = 0;
//	DP[1] = 1;
//	for (int i = 1; i <= 50; i++)
//	{
//		//	printf("%d %lld\n",i, fibo(i));
//	}
//}



//#include<cstdio>
//#include<cstring>
//#define min(a,b) a<b?a:b
//int n, dp[1000001];
//int sol(int i)
//{
//	if (i == n)return 0;
//	int &ret = dp[i];
//	if (ret != -1)return ret;
//
//	ret = 9877654321;
//	if (i * 3 <= n)
//		ret = min(ret, sol(i * 3) + 1);
//	if (i * 2 <= n)
//		ret = min(ret, sol(i * 2) + 1);
//	if (i + 1 <= n)
//		ret = min(ret, sol(i + 1) + 1);
//	else
//		ret = 0;
//	return ret;
//}
//int main()
//{
//	scanf("%d", &n);
//	memset(dp, -1, sizeof(dp));
//	printf("%d", sol(1));
//}

//
//#include<cstdio>
//#include<cstring>
//#define MIN(a,b) a<b?a:b
//int n, k;
//int D[10001];
//int map[101];
//int sol(int i)
//{
//	if (i == 0)return 0;
//	int &ret = D[i];
//	if (ret != -1)return ret;
//	ret = 987654321;
//	for (int c = n-1; c >= 0; c--)
//	{
//		if (i - map[c] >= 0)
//			ret = MIN(ret, sol(i - map[c]) + 1);
//	}
//	return ret;
//}
//
//int main()
//{
//	scanf("%d %d", &n, &k);
//	for (int i = 0; i < n; i++)
//		scanf("%d", &map[i]);
//	memset(D, -1, sizeof(D));
//	printf("%d", sol(k));
//}

//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#define INF 1987654321
//using namespace std;
//int arr[10001];
//int cache[10001];
//int n, k;
//int recur(int x)
//{
//	if (x == k) return 0;
//	int &ret = cache[x];
//	if (ret != -1) return ret;
//	ret = INF;
//	for (int i = n - 1; i >=0 ; i--)
//	{
//		if (x + arr[i] <= k)
//			ret = min(ret, recur(x + arr[i]) + 1);
//	}
//	return ret;
//}
//
//int main()
//{
//	scanf("%d %d", &n, &k);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	for (int i = 0; i <= k;i++)
//		cache[i] = -1;
//	printf("%d\n", recur(0));
//}



#include<cstdio>
#include<cstring>
#define max(a,b) a>b?a:b
int N, map[101][101], D[101][101];

int sol(int y, int x)
{
	if (x == N&&y == N)return 0;
	int &ret = D[y][x];
	if (ret != -1)return ret;
	ret = 0;
	if (y ==0)
		ret = map[1][1] + sol(1, 1);
	else
	{
		if (y < N)
			ret = max(ret, map[y + 1][x] + sol(y + 1, x));
		if (x < N)
			ret = max(ret,map[y][x + 1] + sol(y, x + 1));
	}
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);

	memset(D, -1, sizeof(D));
	printf("%d", sol(0, 0));
}