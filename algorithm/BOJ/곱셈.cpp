#include<cstdio>
typedef long long ll;
int main() {
	long long A, B, C;
	scanf("%lld%lld%lld",&A ,&B ,&C);
	
	ll ret = 1;
	ll pow = A;
	for (int i = B; i > 0; i /= 2)
	{
		if (i & 1)
			ret *= pow;
		pow *= pow;
		pow %= C;
		ret %= C;
	}
	printf("%lld", ret);
}