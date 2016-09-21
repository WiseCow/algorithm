#include<cstdio>
#include<cstring>
long long D[101][101][101],N, L, R;
int main()
{
	scanf("%d %d %d", &N, &L, &R);

	D[1][1][1] = 1;
	for (int n = 2; n <= N; n++)
		for (int l = 1; l <= L; l++)
			for (int r = 1; r <= R;r++)
			{ 
				D[n][l][r] = D[n - 1][l - 1][r] + D[n - 1][l][r - 1] + D[n - 1][l][r] * (n - 2);
				D[n][l][r] %= 1000000007;
			}

	printf("%lld", D[N][L][R]);
}
