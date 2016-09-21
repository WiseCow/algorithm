#include<cstdio>
#include<stack>
using namespace std;
long long in[500001];
long long cnt;
int main()
{
	int N;
	scanf("%d", &N);

	stack<int>st;
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &in[i]);

		int chk = 0;
		while (!st.empty() && in[st.top()] <= in[i])
		{
			//printf("%lld %lld\n", in[st.top()], in[i]);
			cnt++;
			if (in[st.top()] == in[i])
			{
				chk = 1;
				break;
			}
			
			st.pop();
		}
		if (!st.empty()&&st.top() != i&&chk!=1)
		{
			cnt++;
			//printf("%lld %lld\n", in[st.top()], in[i]);
		}
		st.push(i);
	}
	printf("%lld\n", cnt);



}