#include<stdio.h>
typedef long long ll;
const int mod = 1000000007;
int main()
{

	long long a;
	int i;
	scanf("%lld", &a);
	ll b;
	ll c = 0;
	ll d = 1;
	for (i= 2; i <= a % 1500000; i++)
	{
		arr[i] = arr[i-1] + arr[i - 2];
		arr[i] %= 1000000;
	}
	printf("%lld", arr[a% 1500000]);

}