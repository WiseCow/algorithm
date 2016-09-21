#include<iostream>
using namespace std;
int N,in[501][2], D[501][501];
int solve(int s, int f)
{
	if (D[s][f])
		return D[s][f];
	if (s == f)
		return 0;
	int& ans = D[s][f];
	ans = -1;
	for (int i = s; i < f; i++)
	{
		int d1 = solve(s, i);
		int d2 = solve(i + 1, f);
		if (ans == -1 || ans > d1 + d2 + in[s][0] * in[i][1] * in[f][1])
			ans = d1 + d2 + in[s][0] * in[i][1] * in[f][1];
	}
	return ans;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &in[i][0], &in[i][1]);
	cout << solve(1, N) << '\n';
}