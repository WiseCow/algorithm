#include<iostream>
#include<stdio.h>
using namespace std;
#define Max 1000000000

int GCD(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		GCD(b, a%b);
}

int main()
{
	int count[2];
	int ins[1001][2];
	long long ans = 1;
	int flag = 0;

	for (int i = 0; i < 2; i++)
	{
		cin >> count[i];
		for (int j = 0; j < count[i]; j++)
		{
			cin >> ins[j][i];
		}
	}

	for (int i = 0; i < count[0]; i++)
	{
		for (int j = 0; j < count[1]; j++)
		{
			int gcd = GCD(ins[i][0], ins[j][1]);
			ans *= gcd;
			ins[i][0] /= gcd, ins[j][1] /= gcd;
			if (ans >= Max)	ans %= Max, flag = 1;
		}
	}

	if (flag == 1)printf("%09d", ans);
	else cout << ans;
}
