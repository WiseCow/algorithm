#include<iostream>
using namespace std;
long long arr[100];
int main()
{
	int N;
	scanf("%d", &N);
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;

	for (int i = 3; i <= N; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	printf("%lld\n", arr[N]);
}