#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b))?(a):(b)
int arr[301][301];
int D[301][301];
int N, M, K;

int sol(int now,int use)
{
	if (now == N)
		return 0;
	int &ret = D[now][use];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = now + 1; i <= N; i++) {
		if(arr[now][i]!=0&&(use+1<M||(use+1==M&&i==N)))
			ret = max(ret, arr[now][i] + sol(i, use + 1));
	}
	return ret;
}
int main()
{
	
	scanf("%d %d %d", &N, &M, &K);
	memset(D, -1, sizeof(D));
	for (int i = 1; i <= K; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (arr[a][b] < c)
			arr[a][b] = c;
	}
	printf("%d", sol(1,1));

}