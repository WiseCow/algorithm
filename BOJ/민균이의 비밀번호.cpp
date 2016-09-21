#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int N;
map<string, int> m;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		string a,b;
		cin >> a;
		b = a;
		if (m.find(a) == m.end())
		{
			reverse(a.begin(),a.end());
			m.insert({ a, m.size() });
			if (m.find(b) != m.end())
			{
				printf("%d %c\n", a.size(), a[a.size() / 2]);
				return 0;
			}
		}
		else
		{
			printf("%d %c\n", a.size(), a[a.size() / 2]);
			return 0;
		}
	}
}