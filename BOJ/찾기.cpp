#include<iostream>
#include<string>
#include<vector>
using namespace std;
string a, b;
const int MOD = 1e9 + 7;
typedef long long ll;
int p(int a, int b) {
	if (b == 0)
		return 1;
	int temp = p(a, b / 2);
	if (b & 1) {
		return (((ll)temp*temp) % MOD*a) % MOD;
	}
	return ((ll)temp*temp) % MOD;
}
int main() {
	getline(cin, a);
	getline(cin, b);
	int X = 0;
	int t = p(26, b.size() - 1);
	for (int i = 0; i<b.size(); i++)
		X = ((ll)X * 26 + b[i]) % MOD;
	vector<int> ans;
	int T = 0;
	for (int i = 0; i + b.size()<a.size() + 1; i++) {
		if (i == 0) {
			for (int j = 0; j<b.size(); j++) {
				T = ((ll)T * 26 + a[j]) % MOD;
			}
		}
		else {
			T = (MOD + T - ((ll)a[i - 1] * (t)) % MOD) % MOD;
			T = ((ll)T * 26 + a[i + b.size() - 1]) % MOD;
		}
		if (X == T)
			ans.push_back(i);
	}
	printf("%d\n", ans.size());
	for (auto i : ans)
		printf("%d ", i + 1);
	return 0;
}

//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//vector<int> get_PI(string &M)
//{
//	int n = M.size();
//	vector<int> pi(n, 0);
//	int begin = 1, matched = 0;
//	while (begin + matched < n)
//	{
//		if (M[begin + matched] == M[matched])
//		{
//			matched++;
//			pi[begin + matched - 1] = matched;
//		}
//		else
//		{
//			if (matched == 0)
//				begin++;
//			else 
//			{
//				begin = begin + matched - pi[matched - 1];
//				matched = pi[matched - 1];
//			}
//		}
//	}
//	return pi;
//
//}
//vector<int> get_KMP(string &N, string &M)
//{
//	vector<int> ret;
//	vector<int> pi = get_PI(M);
//	int begin = 0, matched = 0;
//
//	int n = N.size();
//	int m = M.size();
//	while (begin <= n - m)
//	{
//		if (matched<m&&N[begin + matched] == M[matched]) {
//			matched++;
//			if (matched == m) {
//				ret.push_back(begin);
//			}
//		}
//		else {
//			if (matched == 0)
//				begin++;
//			else {
//				begin = begin + matched - pi[matched - 1];
//				matched = pi[matched - 1];
//			}
//		}
//	}
//	return ret;
//}
//int main()
//{
//	string N, M;
//	getline(cin, N);
//	getline(cin, M);
//	vector<int> ans = get_KMP(N, M);
//	printf("%d\n", ans.size());
//	for (int i = 0; i < ans.size(); i++)
//		printf("%d ", ans[i] + 1);
//}
//
