#include<iostream>
#include<map>
using namespace std;
long long N,P,Q;
map<long long, long long> cache;
long long sol(int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (cache.count(n) != 0)
	{
		return cache[n];
	}
	else
	{
		cache[n] = sol(n / P) + sol(n / Q);
		return cache[n];
	}
}
int main()
{
	scanf("%lld%lld%lld", &N, &P, &Q);
	printf("%lld\n", sol(N));
}


