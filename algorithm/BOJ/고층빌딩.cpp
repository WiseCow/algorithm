#include<iostream>
using namespace std;
int N, L, R;
long long D[101][101][101];
const int mod = 1000000007;
int main()
{
	scanf("%d %d %d", &N, &L, &R);

	D[1][1][1] = 1;


	for (int n = 2; n <= N; n++)
	{
		for (int l = 1; l <= L; l++)
		{
			for (int r = 1; r <= R; r++)
			{
				D[n][l][r] = D[n - 1][l - 1][r] + D[n - 1][l][r - 1]+ D[n-1][l][r]*(n-2);
				D[n][l][r] %= mod;
			}
		}
	}


	cout << D[N][L][R] << "\n";





}