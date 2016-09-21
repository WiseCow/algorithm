#include<iostream>
#include<queue>
using namespace std;
int num[10001];
int main()
{
	for (int i = 2; i < 10001; i++)
	{
		if (!num[i])
		{
			for (int j = 2; j*i <= 10000; j++)
			{
				num[i*j] = 1;
			}
		}
	}
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{
		int st, en;
		scanf("%d %d", &st, &en);

		int dist[10001] = { 0 };
		queue <pair<int,int>> q;

		q.push({ st,1 });
		while (q.size())
		{
			int now = q.front().first;
			int di = q.front().second;
			q.pop();
			if (dist[now])
				continue;
			dist[now] = di; 
			if (now == en)
				break;
			for (int i = 1; i < 10000;i*=10)
			{
				int n = now / i;
				n %= 10;
				for (int j = 0; j <= 9; j++)
				{
					int k = now - n*i+j*i;
					if (!num[k]&&!dist[k]&&k>=1000)
					{
						q.push({ k,di + 1 });
					}
				}
			}
		}
		if (dist[en] == 0)
			printf("Impossible\n");
		else
			printf("%d\n", dist[en] - 1);
	}
	return 0;
}