#include<iostream>
#define mod 1000000000
using namespace std;
int N, K;
long long D[201][201];

int main()
{
	scanf("%d %d", &N, &K);

	D[0][0] = 1;
	for (int k = 1; k <= K; k++)
		for (int i = 0; i <= N; i++)
			for (int a = 0; a <= i; a++)
			{
				D[i][k] += D[i - a][k - 1];
				D[i][k] %= mod;
			}

	cout << D[N][K] << '\n';
}