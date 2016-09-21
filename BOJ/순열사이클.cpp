#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{
		int N;
		scanf("%d", &N);

		int map[1001] = { 0 };;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &map[i]);
		}
		int group[1001] = { 0 };
		int grno=1;
		for (int i = 1; i <= N; i++)
		{
			if (group[i] != 0)
				continue;
			bool visit[1001] = { 0 };
			
			queue<int> q;
			q.push(i);

			bool chk = 0;
			while (q.size())
			{
				int now = q.front();
				q.pop();

				if (visit[now])
				{
					if (now == i)
						break;
					else
						chk = 1;
					break;
				}
				visit[now] = 1;
				q.push(map[now]);				
			}
			if (chk == 0)
			{
				queue<int> qq;
				qq.push(i);
				while (qq.size())
				{
					int now = qq.front();
					qq.pop();

					if (group[now])
					{
						if (now == i)
							break;
						else
							chk = 1;
						break;
					}
					group[now] = grno;
					qq.push(map[now]);
				}
				grno++;
			}
		}
		printf("%d\n", grno - 1);
	}
}