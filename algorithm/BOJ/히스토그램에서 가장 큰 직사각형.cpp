#include<iostream>
#include<stack>
using namespace std;
int main()
{
	while (1)
	{
		int N;
		scanf("%d", &N);
		if (N==0)
			break;
		int in[100001];
		stack <int> st;
		long long max = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &in[i]);

			while (!st.empty() && in[i] < in[st.top()])
			{
				long long  h = in[st.top()];
				st.pop();
				long long  w = i;
				if(!st.empty())
					w = i-st.top()-1;
				if (max < h*w)
					max = h*w;
			}
			st.push(i);
		}
		while (!st.empty())
		{
			long long  h = in[st.top()];
			st.pop();
			long long w = N;
			if (!st.empty())
				w = N - st.top() - 1;
			if (max < h*w)
				max = h*w;
		}
		printf("%lld\n", max);

	}

}
//#include<iostream>
//#include<stack>
//using namespace std;
//int main()
//{
//	while (1)
//	{
//		int N, in[100001];
//		scanf("%d", &N);
//		if (!N)
//			break;
//
//		stack<int> st;
//		int max = 0;
//		for (int i = 1; i <= N; i++)
//		{
//			scanf("%d", &in[i]);
//			if (i == 1)
//			{
//				st.push(i);
//			}
//			else
//			{
//				if (st.empty() || in[i] >= in[st.top()])
//				{
//					st.push(i);
//				}
//				else
//				{
//					int c = 1;
//					while (!st.empty())
//					{
//						int k = in[st.top()];
//						int n = st.top();
//						st.pop();
//						if (max < k*(i - n))
//							max = k*(i - n);
//						if (st.empty() || in[i] >= in[st.top()])
//						{
//							break;
//						}
//					}
//					st.push(i);
//				}
//			}
//		}
//
//		int p = N+1;
//		while (!st.empty())
//		{
//			int k = in[st.top()];
//			int n = st.top();
//			st.pop();
//			if (max < k*(p - n))
//				max = k*(p - n);
//		}
//		printf("%d\n", max);
//	}
//
//
//}