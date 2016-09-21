#include<iostream>
using namespace std;
long long K;
long long num[100];
long long sum[100];

int main()
{
	scanf("%lld", &K);

	int i = 2;
	num[1] = 1;
	num[2] = 1;
	num[3] = 2;
	sum[1] = 1;
	while (sum[i-1] < K)
	{
		sum[i] = num[i] + sum[i - 1];
		num[i + 1] = num[i] + num[i - 1];
		i++;
	}
	printf("1");
	i--;
	K -= num[i];




	int chk = 1;

	while (K!=0&&K!=4)
	{
		i--;
		if (K > sum[i - 1])
		{
			printf("01");
			K -= num[i];
		}
		else
		{
			printf("0");			
		}
	}
	if (K == 4) printf("01");




}
