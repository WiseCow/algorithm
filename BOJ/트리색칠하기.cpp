#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define INF 987654321
using namespace std;
vector<int> vc[100001];
int D[4][100001];
int n;
int sol(int nc,int now, int pre)
{
	if (vc[now].size() == 1&&pre!=0)
		return nc+1;
	int &ret = D[nc][now];
	if (ret != -1)return ret;
	ret = nc+1;
	for (int i = 0; i < vc[now].size(); i++)
	{
		if (vc[now][i] == pre)
			continue;
		int k = INF;
		for (int j = 0; j < 4; j++)
		{
			if (nc != j)
				k = min(k,sol(j, vc[now][i], now));
		}
		ret += k;
	}
	return ret;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		vc[a].push_back(b);
		vc[b].push_back(a);
	}
	
	memset(D, -1, sizeof(D));
	int ret = sol(0,1,0);
	ret = min(ret, sol(1, 1, 0));
	ret = min(ret, sol(2, 1, 0));
	ret = min(ret, sol(3, 1, 0));
	printf("%d", ret);

}