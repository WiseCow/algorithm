#include<iostream>
using namespace std;
int N;
int D[40];

int main()
{
	scanf("%d", &N);
	D[0] = 1;
	D[2] = 3;
	D[4] = 11;
	for (int i = 6; i <= N; i += 2)
	{
		D[i] = D[i - 2] * 3;
		for (int j = 4; i-j >= 0; j += 2)
			D[i] += D[i - j] * 2;
	}


	cout << D[N] << '\n';
}
