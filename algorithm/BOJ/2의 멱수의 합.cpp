#include<iostream>
using namespace std;
int N;
int D[1000001];
const int mod = 1000000000;

int main()
{
	scanf("%d", &N);
	
	D[0] = 1;
	int n = 1;
	while (n <= N)
	{
		for (int i = n; i <= N; i++)
		{
			D[i] += D[i - n];
			D[i] %= mod;
		}
		n *= 2;
	}
	cout << D[N] << '\n';
}