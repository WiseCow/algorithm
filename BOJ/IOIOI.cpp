#include<iostream>
#include<string>
#include<vector>
using namespace std;
string a,b;
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
	int in,q;
	scanf("%d", &in);
	scanf("%d", &q);
	cin>>a;
	b = "I";
	for (int i = 0; i < in; i++)
		b.append("OI");
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
	return 0;
}