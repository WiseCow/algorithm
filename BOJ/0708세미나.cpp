//#include<cstdio>
//#include<cstring>
//#define MIN(a,b) a<b?a:b
//#define INF 987654321;
//int D[16][1 << 16], N, map[16][16];
//int sol(int now, int visit, int start)
//{
//	if (visit == (1 << N) - 1)
//	{
//		if (map[now][start])
//			return map[now][start];
//		else
//			return INF;
//	}
//	int &ret = D[now][visit];
//	if (ret != -1)return ret;
//	ret = INF;
//	for (int i = 0; i < N; i++)
//	{
//		if (!(visit & (1 << i)) && map[now][i] != 0)
//			ret = MIN(ret, sol(i, visit | (1 << i), start) + map[now][i]);
//	}
//	return ret;
//}
//int main()
//{
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)scanf("%d", &map[i][j]);
//	memset(D, -1, sizeof(D));
//	printf("%d", sol(0, 1, 0));
//}


//#include<cstdio>
//#include<cstring>
//#define MAX(a,b) (a)>(b)?a:b
//int N, map[1001], D[1001],maxx;
//
//int main()
//{
//	scanf("%d", &N);
//	for (int i = 1; i <= N; i++)
//		scanf("%d", &map[i]);
//	memset(D, 1, sizeof(D));
//	D[1] = 1;
//	for (int i = 2 ; i <= N; i++)
//	{
//		D[i] = 1;
//		for (int j = 1; j < i; j++)
//		{
//			if (map[i] > map[j])
//			{
//				D[i] = MAX(D[i], D[j] + 1);
//			}
//		}
//		maxx = MAX(maxx, D[i]);
//	}
//
//	printf("%d", maxx);
//
//}
