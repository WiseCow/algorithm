#include<iostream>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 9;
int cache[1000000][7];
int N, K;
int solve(int idx, int state)
{
	if (idx == N)
		return 1;
	int &ret = cache[idx][state];
	if (ret != -1)
		return ret;
	ret = 0;
	if (state == 0)
	{
		ret += solve(idx + 1, 1);
		ret %= mod;
		ret += ((ll)solve(idx + 1, 0)*(K - 1) % mod);
		ret %= mod;
		return ret;

	}
	if (state == 1)
	{
		ret += solve(idx + 1, 2);
		ret %= mod;
		ret += solve(idx + 1, 1);
		ret %= mod;
		ret += ((ll)solve(idx + 1, 0)*(K - 1))%mod;
		ret %= mod;
		return ret;
	}
	if (state == 2)
	{
		ret += solve(idx + 1, 3);
		ret %= mod;
		ret == solve(idx + 1, 5);
		ret %= mod;
		ret += ((ll)solve(idx + 1, 0)*(K - 2)) % mod;

		ret %= mod;
		return ret;
	}
	if (state == 3)
	{
		ret += solve(idx + 1, 4);
		ret %= mod;
		ret += solve(idx + 1, 1);
		ret %= mod;
		ret += ((ll)solve(idx + 1, 0)*(K - 2)) % mod;
		ret %= mod;
		return ret;

	}
	if (state == 4)
	{
		ret += solve(idx + 1, 3);
		ret %= mod;
		ret += ((ll)solve(idx + 1, 0)*(K - 2)) % mod;
		ret %= mod;
		return ret;
	}
	if (state == 5)
	{
		ret += solve(idx + 1, 6);
		ret %= mod;
		ret += solve(idx + 1, 1);
		ret %= mod;
		ret += ((ll)solve(idx + 1, 0)*(K - 2)) % mod;
		ret %= mod;
		return ret;

	
	}
	ret += solve(idx + 1, 1);
	ret %= mod;
	ret += ((ll)solve(idx + 1, 0)*(K - 2)) % mod;
	ret %= mod;
	return ret;

}
int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d %d", &N, &K);
	printf("%d", solve(0, 0));
}