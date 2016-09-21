#include<cstdio>
int a, b, c;
int main()
{
	scanf("%d", &a);
	while(a--)
	{
		scanf("%d %d", &b, &c);
		printf("You get %d piece(s) and your dad gets %d piece(s).\n", b / c, b%c);
	}
}