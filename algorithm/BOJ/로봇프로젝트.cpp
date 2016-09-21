#include<cstdio>
#include<algorithm>
using namespace std;
int map[1000000];
int mi, ma;
int main()
{
	int x, n,t;
	while (scanf("%d",&x)!=EOF)
	{
		scanf("%d", &n);
		x *= 10000000;
		bool chk = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &map[i]);
		sort(map, map + n);
		int l = 0, r = n - 1;
		while (l < r)
		{
			if (map[l] + map[r] < x)
				l++;
			else if (map[l] + map[r]>x)
				r--;
			else
			{
				chk = 1;
				break;
			}
		}
		if (!chk)
			printf("danger\n");
		else
			printf("yes %d %d\n", map[l], map[r]);
	}
}