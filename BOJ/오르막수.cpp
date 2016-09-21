#include<iostream>
using namespace std;
long long arr[1001][10];
int main()
{

	for (int i = 0; i < 10; i++)
		arr[1][i] = 1;




	int N;
	scanf("%d", &N);




	for (int i = 2; i <= N; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			long long a = 0;
			for (int j = 0; j < 10;j++)
				if (j <= k)
				{
					a += arr[i - 1][j];
					a %= 10007;
				}

			arr[i][k] = a;

		}
	}
	long long a=0;
	for (int i = 0; i < 10; i++)
	{
		a += arr[N][i];
		a %= 10007;

	}
	cout << a << endl;
}