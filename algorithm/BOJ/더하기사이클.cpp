https://www.acmicpc.net/problem/1110
#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,cnt=0;
	scanf("%d", &a);

	b = a / 10;
	c = a % 10;

	while (1)
	{

		d = b + c;
		 b=c;
		c=d%10;
		if (b * 10 + c == a)
			break;
		cnt++;

	}
	cout << cnt+1 << endl;



}