#include<cstdio>
using namespace std;
int main()
{
	long long a;
	scanf("%lld", &a);

	long long res = a;
	for (long long i = 2; i*i <= a; i++)
	{
		if (a%i == 0) {
			while (a%i == 0)
				a /= i;
			res -= res / i;
		}
	}
	if (a > 1)
		res -= res / a;
	printf("%lld", res);


}