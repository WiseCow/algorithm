#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;

int main()
{
	string s;
	cin >> s;
	priority_queue<string> q;
	stack<string> st;
	for (int i = 0; i < s.size(); i++)
		q.push(s.substr(i, s.size()));
	while (q.size())
	{
		st.push(q.top());
		q.pop();
	}
	while (st.size())
	{
	cout<<st.top()<<'\n';
		st.pop();
	}
	return 0;


}
