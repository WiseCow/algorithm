#include<iostream>
using namespace std;
long long arr[101][10];
int main()
{
	for (int i = 1; i < 10; i++)
	{
		arr[1][i] = 1;
	}

	int N;
	scanf("%d", &N);

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			long long a=0;
			if (j != 0)
				a += arr[i - 1][j - 1];
			
			if (j != 9)
				a += arr[i - 1][j + 1];

			arr[i][j] = a % 1000000000;
		}
	}

	long long a = 0;
	for (int i = 0; i < 10; i++)
	{
		a += arr[N][i];
		a %= 1000000000;
	}
	cout << a << endl;

}