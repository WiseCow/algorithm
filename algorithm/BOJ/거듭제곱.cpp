#include<iostream>
using namespace std;
int main()
{
	long long N;
	scanf("%lld", &N);
	long long ans=0;
	long long k = 1;
	long long o = 1;
	while (N != 0)
	{
		if ((N&k) == k)
		{
			N -= k;
			ans += o;
		}
		k *= 2;
		o *= 3;
	}

	cout << ans << endl;









}