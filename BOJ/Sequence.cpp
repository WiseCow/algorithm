#include<iostream>
#include<cstring>
int N, M, K;
int D[12][230][230];
int sol(int n, int m, int use)
{
	if (n == 0)
	{
		if (m == 0)
			return 1;
		return 0;
	}
	int &ret = D[n][m][use];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = use; i <= m; i++)
		ret += sol(n - 1, m - i, i);
	return ret;
}
void print(int n, int m, int use, int sec)
{
	if (n == 0)return;
	int cnt;
	for (int i = use; i <= m; i++)
	{
		cnt = sol(n-1, m-i, i);
		if (sec >= cnt)
			sec -= cnt;
		else
		{
			printf("%d ", i);
			print(n - 1, m - i, i, sec);
			break;
		}
	}


}
int main()
{
	memset(D, -1, sizeof(D));
	scanf("%d%d%d", &N, &M, &K);
	sol(N, M, 1);
	print(N, M, 1, K-1);
}




//#include<string>
//using namespace std;
//int N, M, K;
//int cache[15][300][300];
//int solve(int n, int m, int pre) {
//	if (n == 0) {
//		if (m == 0)
//			return 1;
//		return 0;
//	}
//	int &ret = cache[n][m][pre];
//	if (ret != -1)
//		return ret;
//	ret = 0;
//	for (int i = pre; i <= m; i++) {
//		ret += solve(n - 1, m - i, i);
//	}
//	return ret;
//}
//string get_ans(int n, int m, int pre, int k) {
//	if (n == 0)
//		return "";
//	for (int i = pre; i <= m; i++) {
//		int cnt = solve(n - 1, m - i, i);
//		if (k >= cnt)
//			k -= cnt;
//		else
//			return to_string(i) + " " + get_ans(n - 1, m - i, i, k);
//	}
//}
//int main() {
//	memset(cache, -1, sizeof(cache));
//	scanf("%d%d%d", &N, &M, &K);
//	solve(N, M, 1);
//	cout << get_ans(N, M, 1, K - 1) << endl;
//	return 0;
//}