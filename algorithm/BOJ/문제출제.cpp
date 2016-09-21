#include<iostream>
using namespace std;
int A[100001];
int B[100001];
long long D[100001][2];
const int mod = 1000000007;
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++)
	{
		scanf("%d", &A[i]);
	}

	for (int i = 2; i <= tc; i++)
	{
		scanf("%d", &B[i]);
	}

	D[0][0] = 1;
	D[0][1] = 0;
	for (int i = 1; i <= tc; ++i)
	{
		D[i][0] = (D[i - 1][0] * (A[i] + B[i]) + D[i - 1][1] * (A[i] + B[i] - 1)) % mod;
		D[i][1] = (D[i - 1][0] * B[i+1] + D[i - 1][1] * B[i+1]) % mod;
	}


	printf("%lld\n", D[tc][0]);
	return 0;


}

