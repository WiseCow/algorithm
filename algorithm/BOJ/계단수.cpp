#include<cstdio>
#include<cstring>
#define inf 1000000000
int D[101][11][1<<10];
int N;
long long sol(int n, int idx, int now)
{
	

	if (idx == -1 || idx == 10)
		return 0;
	int &res = D[n][idx][now];
	if (n == N&&now == 1023)
		return 1;
	if (n == N)
		return 0;


	if (res != -1)return res;

	res = sol(n + 1, idx + 1, now | (1 << idx + 1)) % inf + sol(n + 1, idx - 1, now | (1 << idx - 1)) % inf;
	return res% inf;
}


int main()
{
	scanf("%d", &N);
	memset(D, -1, sizeof(D));


	long long res = 0;
	for (int i = 1; i <= 9; i++)
	{
		res += sol(1, i, 1<<i);
		res %= inf;
	}
	printf("%lld", res % inf);

}

//include<cstdio>
//#include<cstring>
//#define mod 1000000000
//
//int N;
//int cache[11][101][1 << 10];
//int search(int pivot, int len, int visit)
//{
//	if (pivot == -1 || pivot == 10)
//		return 0;
//	if (len == N && visit == (1 << 10) - 1)
//		return 1;
//	if (len == N)
//		return 0;
//
//	int &ret = cache[pivot][len][visit];
//
//	if (ret != -1)
//		return ret;
//
//	ret = (search(pivot - 1, len + 1, visit | (1 << pivot - 1)) +
//		search(pivot + 1, len + 1, visit | (1 << pivot + 1))) % mod;
//
//	return ret % mod;
//}
//
//
//
//int main(void)
//{
//	memset(cache, -1, sizeof(cache));
//	scanf("%d", &N);
//
//	int cnt = 0;
//	for (int i = 1; i < 10; i++)
//	{
//		int tmp = search(i, 1, 0 | (1 << i)) % mod;
//		cnt += tmp;
//		cnt %= mod;
//	}
//	printf("%d\n", cnt%mod);
//	return 0;
//}
