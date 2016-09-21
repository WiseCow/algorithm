#include<cstdio>
int t, n, cheet[3][3] = { 0,0,1,1,0,0,0,1,0 }, n1, n2;
char p1[2], p2[2];
int conv(char a[2])
{
	if (a[0] == 'R')
		return 0;
	if (a[0] == 'P')
		return 1;
	return 2;
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		int cnt[2] = { 0 };
		scanf("%d", &n);
		for (int p = 0; p < n; p++)
		{
			scanf("%s%s", p1, p2);
			n1 = conv(p1);
			n2 = conv(p2);
			cnt[0] += cheet[n1][n2];
			cnt[1] += cheet[n2][n1];
		}
		if (cnt[0] > cnt[1])
			printf("Player 1\n");
		else if (cnt[0] < cnt[1])
			printf("Player 2\n");
		else
			printf("TIE\n");
	}
}