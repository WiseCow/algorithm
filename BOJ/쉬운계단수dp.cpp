#include<iostream>
using namespace std;
long long D[101][10];
int N;
const int mod = 1000000000;
int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= 9; i++)
		D[1][i] = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			D[i][j] += D[i - 1][j + 1];
			D[i][j] %= mod;
		}

		for (int j = 1; j < 10; j++)
		{
			D[i][j] += D[i - 1][j - 1];
			D[i][j] %= mod;
		}

	}
	long long sum = 0;
	for (int i = 0; i <= 9; i++)
	{
		sum += D[N][i];
		sum %= mod;
	}

	cout << sum << "\n";
}