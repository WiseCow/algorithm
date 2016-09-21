#include<iostream>
using namespace std;
typedef long long ll;

int N, R, G, B;
ll d[11][101][101][101];
ll fact[11];

ll solve(int idx, int r, int g, int b) {

	if (r < 0 || g < 0 || b < 0)
		return 0;

	if (idx == N + 1)
		return 1;

	ll &re = d[idx][r][g][b];
	if (re != -1)return re;

	re = 0;
	if (idx % 2 == 0) {
		int pick = idx / 2;
		ll multi = fact[idx] / fact[pick] / fact[pick];
		//rg
		re += solve(idx + 1, r - pick, g - pick, b)*multi;
		//rb
		re += solve(idx + 1, r - pick, g, b - pick)*multi;
		//bc
		re += solve(idx + 1, r, g - pick, b - pick)*multi;
	}

	if (idx % 3 == 0)
	{
		int pick = idx / 3;
		ll multi = fact[idx] / fact[pick] / fact[pick];
		re += solve(idx + 1, r - pick, g - pick, b - pick)*multi;
	}
	re += solve(idx + 1, r - idx, g, b);
	re += solve(idx + 1, r, g - idx, b);
	re += solve(idx + 1, r, g, b - idx);
	return re;

}


int main() {

	fact[0] = 1;
	for (int i = 1; i < 11; i++)
		fact[i] = i*fact[i - 1];
	memset(d, -1, sizeof(d));
	scanf("%d%d%d%d", &N, &R, &G, &B);
	printf("%lld\n", solve(1, R, G, B));




	return 0;
}