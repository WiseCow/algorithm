//https://www.acmicpc.net/problem/1788
#include<iostream>
using namespace std;
long long fibo[1000002] = { 0,1 };
int _abs(int a)
{
	return a >= 0 ? a : -a;
}
int main()
{
	int a;
	scanf("%d", &a);

	if (a != 0)
	{
		for (int i = 2; i <= _abs(a); i++)
			fibo[i] = (fibo[i - 1] + fibo[i - 2])%1000000000;
		if (a > 0)
			printf("1\n");
		else
			if (_abs(a) % 2 == 0)
				printf("-1\n");
			else
				printf("1\n");
		printf("%lld\n", fibo[_abs(a)]);
	}

	else
		printf("0\n0\n");







}