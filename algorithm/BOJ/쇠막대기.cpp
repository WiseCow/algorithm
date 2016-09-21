#include<iostream>
#include<stack>
using namespace std;
int main()
{
	char arr[100002] = { 0 };
	scanf("%s", &arr[1]);
	stack<int> st;
	long long res=0;
	for (int i = 1; arr[i] != 0; i++)
	{
		if (arr[i] == '(')
			st.push(i);
		else
		{
			st.pop();
			if (arr[i - 1] == '(')
				res += st.size();
			else
				res += 1;
		}
	}
	printf("%lld\n", res);
}