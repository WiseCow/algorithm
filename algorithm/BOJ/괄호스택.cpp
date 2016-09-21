#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	char arr[51];
	for (int i = 0; i < N; i++)
	{
		scanf("%s", &arr);
		stack<int> st;
		bool chk = 0;
		for (int i = 0; arr[i] != 0; i++)
		{
			if (arr[i] == '(')
			{
				st.push(i);
			}
			else
			{
				if (st.size())
					st.pop();
				else
					chk = 1;
			}
		}
		if (st.size())
			chk = 1;

		if (chk == 1)
			printf("NO\n");
		else
			printf("YES\n");
	}
}