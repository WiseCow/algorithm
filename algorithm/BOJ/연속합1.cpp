#include<cstdio>
#define MAX(a,b) a>b?a:b
int n, map[100001];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &map[i]);
	for (int i = 2; i <= n; i++)
	{
		if (map[i] < map[i - 1] + map[i])
			map[i] =map[i - 1] + map[i];
	}
	int mx = map[1];
	for (int i = 2; i <= n; i++)
		mx = MAX(mx, map[i]);
	printf("%d", mx);
}