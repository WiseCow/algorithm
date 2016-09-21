#include<iostream>
using namespace std;
int N, M, in[101], d[101][101], s[101];
int solve(int e, int g)
{
	if (g == 0)return 0;
	if (e <= 0) return -98765432;
	if (d[e][g])return d[e][g];
	int &res = d[e][g];
	res = solve(e-1,g);
	for (int i = 1; i <= e; i++)
	{
		int cmp = solve(i - 2,g - 1) + s[e] - s[i - 1];
		if (res < cmp) res = cmp;
	}
	return res;
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &in[i]);
		s[i] = s[i - 1] + in[i];
	}
	cout << solve(N, M) << '\n';

}