#include<iostream>
#include<stack>
using namespace std;
int N, map[100001];
int main()
{
		scanf("%d", &N);
		stack <int> st;
		long long max = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &map[i]);

			while (!st.empty() && map[i] < map[st.top()])
			{
				long long  h = map[st.top()];
				st.pop();
				long long  w = i;
				if (!st.empty())
					w = i - st.top() - 1;
				if (max < h*w)
					max = h*w;
			}
			st.push(i);
		}
		while (!st.empty())
		{
			long long  h = map[st.top()];
			st.pop();
			long long w = N;
			if (!st.empty())
				w = N - st.top() - 1;
			if (max < h*w)
				max = h*w;
		}
		printf("%lld\n", max);

}