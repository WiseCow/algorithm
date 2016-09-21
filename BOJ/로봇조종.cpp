#include<cstdio>
#include<cstring>
int in[501][501];
int D[501][501];
int N;
int find(int floor, int position)
{
	if (floor == N + 1)
		return 0;
	int &ret = D[floor][position];
	if (ret != -1)return ret;
	int t1 = find(floor+1,position), t2 = find(floor+1,position+1);
	ret = in[floor][position];
	return ret += t1 > t2 ? t1 : t2;
}
int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &in[i][j]);
	memset(D, -1, sizeof(D));
	printf("%d", find(1, 1));
}