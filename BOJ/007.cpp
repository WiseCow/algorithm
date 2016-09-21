#include<cstdio>
#include<algorithm>
using namespace std;
double D[1 << 20];
int map[20][20];
int N;
double sol(int idx, int state)
{
	if (idx == N)return 1;
	double &ret = D[state];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = 0; i < N; i++)
	{
		if (state&(1 << i))
			continue;
		ret = max(ret, sol(idx + 1, state | (1 << i))*map[idx][i]/100.0);
	}
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	for (int i = 0; i < 1 << N; i++)
		D[i] = -1.0;
	printf("%lf", sol(0,0)*100);
}