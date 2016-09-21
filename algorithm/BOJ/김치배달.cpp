#include<cstdio>
#include<cstring>
#include<algorithm>
#define MIN(a,b) ((a)<(b))?a:b
#define INF 987654321;
using namespace std;
int map[1001], N, L, D[2][1001][1001];

int sol(int kim, int po, int left, int right)
{
	if (left == 0 && right == N)return 0;

	int &ret = D[po][left][right];
	if (ret != -1)return ret;
	ret = INF;

	if (po == 0)
	{
		if (left != 0)
			ret = MIN(ret, sol(kim - 1, 0, left - 1, right) + (map[left] - map[left - 1])*kim);
		if (right != N)
			ret = MIN(ret, sol(kim - 1, 1, left, right + 1) + (map[right + 1] - map[left])*kim);
	}
	else
	{
		if (left != 0)
			ret = MIN(ret, sol(kim - 1, 0, left - 1, right) + (map[right] - map[left - 1])*kim);
		if (right != N)
			ret = MIN(ret, sol(kim - 1, 1, left, right + 1) + (map[right + 1] - map[right])*kim);
	}
	return ret;
}
int main()
{
	scanf("%d %d", &N, &L);
	map[0] = L;
	for (int i = 1; i <= N; i++)
		scanf("%d", &map[i]);
	sort(map, map + N + 1);
	int find = 0;
	for (int i = 0; i <= N; i++)
	{
		if (map[i] == L)
		{
			find = i;
			break;
		}
	}
	memset(D, -1, sizeof(D));
	int ret = INF;
	if (find != 0)
		ret = MIN(ret, sol(N - 1, 0, find - 1, find) + (map[find] - map[find - 1])*N);
	if (find != N)
		ret = MIN(ret, sol(N - 1, 1, find, find + 1) + (map[find + 1] - map[find])*N);
	printf("%d", ret);
}