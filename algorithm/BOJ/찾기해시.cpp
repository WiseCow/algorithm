#include<iostream>
#include<string>
#include<vector>
typedef long long ll;
const int mod = 1e9 + 7;
using namespace std;
string a, b;

int p(int a, int b)
{
	if (b == 0)return 1;
	int tmp = p(a, b / 2);
	if (b & 1)
	{
		return (((ll)tmp*tmp) % mod*a) % mod;
	}
	return ((ll)tmp*tmp) % mod;
}
int main()
{
	getline(cin,a);
	getline(cin, b);
	int t = p(26, b.size()-1);
	int X = 0;
	for (int i = 0; i < b.size(); i++)
		X = ((ll)X * 26 + b[i])%mod;
	vector<int> ans;
	int T = 0;
	for (int i = 0; i + b.size() < a.size() + 1; i++)
	{
		if (i == 0)
		{
			for (int h = 0; h < b.size(); h++)
				T = ((ll)T * 26 + a[h]) % mod;
		}
		else
		{
			T = (mod + T - ((ll)a[i - 1] * (t)) % mod) % mod;
			T = ((ll)T * 26 + a[i + b.size() - 1]) % mod;
		}
		if (T == X)
			ans.push_back(i + 1);
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
}

//
//
//
//#include<iostream>
//#include<cstring>
//#include<vector>
//#include<string>
//const int mod = 1e9 + 7;
//using namespace std;
//string a, b;
//typedef long long ll;
//int p(int a, int b)
//{
//	if (b == 0)return 1;
//	int tmp = p(a, b / 2);
//	if (b & 1)
//	{
//		return (((ll)tmp*tmp) % mod*a) % mod;
//	}
//	return ((ll)tmp*tmp) % mod;
//}
//int main()
//{
//	getline(cin, a);
//	getline(cin, b);
//	int X = 0;
//	int t = p(26, b.size() - 1);
//	for (int i = 0; i < b.size(); i++)
//		X = ((ll)X * 26 + b[i]) % mod;
//
//	vector<int>ans;
//	int T = 0;
//	for (int i = 0; i + b.size() < a.size() + 1; i++)
//	{
//		if (i == 0)
//		{
//			for (int j = 0; j < b.size(); j++)
//			{
//				T = ((ll)T * 26 + a[j]) % mod;
//			}
//		}
//		else
//		{
//			T = (mod + T - ((ll)a[i - 1] * (t)) % mod) % mod;
//			T = ((ll)T * 26 + a[i+b.size() - 1]) % mod;
//		}
//		if (X == T)
//			ans.push_back(i);
//	}
//	printf("%d\n", ans.size());
//	for (int i = 0; i < ans.size(); i++)
//		printf("%d ", ans[i]+1);
//
//}
