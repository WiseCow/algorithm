#include<iostream>
using namespace std;
char input[100000];
int arr[21];
int main()
{

	int N, K;
	scanf("%d %d", &N, &K);

	scanf("%s", &input);

	int p = 0;
	int arp = 1;
	int sum = 0;
	bool chk = 0;
	while (input[p] != 0)
	{
		if (input[p] != ',')
		{
			if (input[p] != '-')
			{
				sum *= 10;
				sum += input[p] - '0';
			}
			else
				chk++;
		}
		else
		{
			if (chk == 1)
				sum *= -1;
			arr[arp++] = sum;
			chk = 0;
			sum = 0;
		}
		p++;
	}
	if (chk == 1)
		sum *= -1;
	arr[arp++] = sum;


	for (int i = 1; i <= K; i++)
	{
		for (int j = 1; j<= N-i; j++)
		{
			arr[j] = arr[j + 1] - arr[j];
		}
	}

	for (int i = 1; i <= N - K; i++)
	{
		if (i != 1)
			printf(",");
		printf("%d", arr[i]);
	}


	printf("\n");
}