//https://www.acmicpc.net/problem/2292
#include<iostream>
using namespace std;
int main()
{
	int a, b=2, c=0,d=1;
	scanf("%d", &a);

	while (a >= b)
	{
		c += 6;
		b += c;
		d++;
	}

	printf("%d",d);
}