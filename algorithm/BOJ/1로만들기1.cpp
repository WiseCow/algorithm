#include<cstdio>
#include<cstring>
#define MIN(a,b) a<b?a:b
int N, DP[1000001];
int sol(int i)
{
	if (i == N)return 0;
	
	int &ret = DP[i];
	if (ret != -1)return ret;
	if (i <= N - 1)
		ret = sol(i + 1) + 1;
	else
		ret = 0;
	if (i * 3 <= N)
		ret = MIN(ret, sol(i * 3) + 1);
	if (i * 2 <= N)
		ret = MIN(ret, sol(i * 2) + 1);
	return ret;

}
int main()
{
	scanf("%d", &N);
	memset(DP, -1, sizeof(DP));
	printf("%d", sol(1));
}