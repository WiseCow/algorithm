#include<cstdio>
long long D[100];
int main()
{
	int N;
	scanf("%d", &N);
	D[1] = D[2] = 1;
	long long  sum = 1;
	for (int i =3; i <= N; i++)
	{
		D[i] = sum + 1;
		sum += D[i-1];
	}
	printf("%lld", D[N]);
}