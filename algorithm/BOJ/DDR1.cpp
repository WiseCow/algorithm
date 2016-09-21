#include<cstdio>
#include<cstring>
#define MIN(a,b) a<b?a:b
#define INF 987654321
int map[100001], p, D[5][5][100001], difmap[5][5] = { {0,2,2,2,2},{0,1,3,4,3},{0,3,1,3,4},{0,4,3,1,3},{0,3,4,3,1} };
int sol(int l, int r, int now)
{
	if (now == p)return 0;
	int &ret = D[l][r][now];
	if (ret != -1)return ret;
	ret = INF;
	int ltonext=difmap[l][map[now+1]];
	int rtonext = difmap[r][map[now + 1]];
	if(map[now + 1]!=r)
	ret = MIN(ret, sol(map[now + 1], r, now + 1)+ltonext);
	if (map[now + 1] != l)
	ret = MIN(ret, sol(l, map[now + 1], now + 1)+rtonext);
	return ret;
}
int main()
{
	while(1)
	{
		p++;
		scanf("%d", &map[p]);
		if (map[p] == 0)break;
	}
	memset(D, -1, sizeof(D));
	printf("%d",sol(0, 0, 0));
}