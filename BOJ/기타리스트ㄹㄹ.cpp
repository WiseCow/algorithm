#include<cstdio>
#include<cstring>
int arr[101];
int D[101][1001];
int N, S, M;
int sol(int now, int S)
{
	if (now == N+1)
		return S;

	int &ret = D[now][S];
	if (ret != -2)return ret;
	int t = -1;
	if (S + arr[now] <= M) ret = sol(now + 1, S + arr[now]);
	if (S - arr[now] >= 0) t= sol(now + 1, S - arr[now][);
	if (ret < t)ret = t;
	return ret;
}
int main()
{
	
	scanf("%d %d %d", &N, &S, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= N; i++)
		for (int j = 0; j <= M; j++)
			D[i][j] = -2;
	printf("%d", sol(1,S));
}