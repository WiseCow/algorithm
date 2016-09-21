#include<iostream>
#define max(a,b) ((a)<(b))?b:a

using namespace std;
int N;
int in[10001];
int D[10001];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &in[i]);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			D[i] = max(D[i], D[i - j] + in[j]);
		}
	}

	cout << D[N] << '\n';

	return 0;

}