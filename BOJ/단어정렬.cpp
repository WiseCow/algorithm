//https://www.acmicpc.net/problem/1181
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool chk(const string &a, const string &b)
{
	if (a.size() == b.size())
	{
		return a < b;
	}
	else
	{
		return a.size() < b.size();
	}
}

int main()
{
	int tc;
	cin >> tc;


	vector <string> st(tc);
	for (int i = 0; i < tc; i++)
	{
		cin >> st[i];
	}


	sort(st.begin(), st.end(),chk);

	st.erase(unique(st.begin(), st.end()), st.end());

	for (int i = 0; i < st.size(); i++)
	{
		cout << st[i] << endl;
	}
}