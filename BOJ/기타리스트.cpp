#include<cstdio>
#define inf -987654321
int N, S, M;
int arr[101],D[101][1001];
int sol(int now, int st)
{
	int& res = D[now][st];
	if (res != inf) return res;
	if (now == N) return st;
	int tmp = -1;
	if (st + arr[now] <= M)res = sol(now + 1, st + arr[now]);
	if (st - arr[now] >= 0)tmp = sol(now + 1, st - arr[now]);
	if (tmp > res) res = tmp;
	return res;
}
int main()
{
	scanf("%d %d %d", &N, &S, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i <= N; i++)
		for (int j = 0; j < 1001; j++)
			D[i][j] = inf;
	printf("%d", sol(0, S));
}




//#include<iostream>
//#include<vector>
//using namespace std;
//int arr[111];
//vector<int> in[111];
//int maxx = 0;
//int N, S, M;
//bool chk = 0;
//void sol(int n)
//{
//	int cnt = 0;
//	for (int i = 0; i < in[n].size(); i++)
//	{
//		int a = in[n][i];
//		if (a + arr[n + 1] >= 0 && a + arr[n + 1] <= M)
//		{
//			cnt++;
//			in[n + 1].push_back(a + arr[n + 1]);
//			if (n==N-1&&a + arr[n + 1]>maxx)
//				maxx = a + arr[n + 1];
//		}
//		if (a - arr[n + 1] >= 0 && a - arr[n + 1] <= M)
//		{
//			cnt++;
//			in[n + 1].push_back(a - arr[n + 1]);
//			if (n==N-1&&a - arr[n + 1]>maxx)
//				maxx = a - arr[n + 1];
//		}
//	}
//	if (cnt == 0)
//		chk = 1;
//}
//int main()
//{
//	scanf("%d %d %d", &N, &S, &M);
//	for (int i = 1; i <= N; i++)
//		scanf("%d", &arr[i]);
//	in[0].push_back(S);
//	for (int i = 0; i < N&&in[i].size(); i++)
//		sol(i);
//	if (chk)
//		printf("-1\n");
//	else
//		printf("%d\n", maxx);
//}