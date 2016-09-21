#include<cstdio>
int N[1001];
int n, m, l, cnt, now;

int main()
{
	scanf("%d%d%d", &n, &m, &l);
	while (1)
	{
		cnt++;
		if (now < 0)
			now = n + now;
		else if (now>=n)
			now = now - n;
		N[now]++;
		if (N[now] == m)
		{
			printf("%d", cnt);
			break;
		}
		if (N[now] & 1)
			now -= (l%n);
		else
			now += (l%n);
	}



}