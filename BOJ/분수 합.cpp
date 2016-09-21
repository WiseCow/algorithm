//https://www.acmicpc.net/problem/1735
#include<iostream>
using namespace std;
int GCD(int a, int b)
{
	if (b == 0)
		return  a;
	else
		return GCD(b, a%b);
}

int main()
{

	int a, b, c, d;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);


	int mo=b*d, ja= a*d + b*c;
	int gcd = GCD(ja, mo);
	printf("%d %d\n", ja/gcd, mo/gcd);
}