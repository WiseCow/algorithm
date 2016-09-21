#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, map[256];
int D[256][256];
int wi[256][256];

int sol(int s, int f)
{
	if (s == f)return 0;
	int &ret = D[s][f];
	if (ret != -1)return ret;
	ret = 0x3f3f3f3f;
	for (int i = s; i < f; i++)
	{
		ret = min(ret, sol(s, i) + sol(i + 1, f) + abs(wi[s][i] - wi[i + 1][f]));
	}
	return ret;
}
int main()
{
	memset(D, -1, sizeof(D));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &map[i]);
	for (int i = 0; i < n; i++)
	{
		wi[i][i] = map[i];
		for (int j = i + 1; j < n; j++)
			wi[i][j] = min(wi[i][j - 1], map[j]);
	}
	printf("%d", sol(0, n - 1));
}