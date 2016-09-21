https://www.acmicpc.net/problem/1085
#include<iostream>
using namespace std;
int main()
{
	int a, b, c, d;
	scanf("%d %d %d %d",&a, &b, &c, &d);
	
	int min=999999;
	if (a < min)
		min = a;
	if (b < min)
		min = b;
	if (c-a < min)
		min = c-a;
	if (d-b < min)
		min = d-b;

	printf("%d\n", min);

}