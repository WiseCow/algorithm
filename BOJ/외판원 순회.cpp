#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,map[16][16],D[16][1 << 16];
int sol(int now, int state)
{
	if (state == (1 << n) - 1)
		return map[now][0];
	int &ret = D[now][state];
	if (ret != -1)return ret;
	ret = 0x3f3f3f3f;
	for (int i = 0; i < n; i++)
	{
		if (map[now][i] != 0)
		{
			if ((state&1 << i) != 1 << i)
				ret = min(ret, sol(i, state | (1 << i))+map[now][i]);
		}
	}
	return ret;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	memset(D, -1, sizeof(D));
	printf("%d", sol(0, 1));
}