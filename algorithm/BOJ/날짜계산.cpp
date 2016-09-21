#include<cstdio>
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int aa = 1, bb = 1, cc = 1;


	int k = 1;
	while (1)
	{
		if (aa == a&&bb == b&&cc == c)
			break;
		aa++;
		bb++;
		cc++;
		if (aa == 16)
			aa = 1;
		if (bb == 29)
			bb = 1;
		if (cc == 20)
			cc = 1;
		k++;
	}
	printf("%d\n", k);
}