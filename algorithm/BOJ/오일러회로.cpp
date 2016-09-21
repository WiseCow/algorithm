#include<iostream>
#include<stack>

using namespace std;
int N,sum[1001];
int map[1001][1001];
stack <int> st;
stack <int> ans;
void sol(int now)
{
	st.push(now);
	bool chk = 0;
	for (int i = 0; i < N; i++)
	{
		if (map[now][i]>0)
		{
			map[now][i]--;
			map[i][now]--;
			sol(i);
			break;
			chk = 1;
		}
	}
	if (!chk)
	{
		
		while (st.size())
		{
			now = st.top();
			bool chk = 0;
			for (int i = 0; i < N; i++)
			{
				if (map[now][i]>0)
				{
					map[now][i]--;
					map[i][now]--;
					sol(i);
					break;
					chk = 1;
				}
			}
			if (chk)
				break;
			if (st.size())
			{
				ans.push(st.top());
				st.pop();
			}
		}
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
			sum[i] += map[i][j];
		}
	bool chk = 0;
	for (int i = 0; i < N; i++)if (sum[i] & 1)chk = 1;
	if (chk)
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		
		sol(0);
		while (ans.size())
		{
			printf("%d ", ans.top()+1);
			ans.pop();
		}
		printf("\n");
	}

}