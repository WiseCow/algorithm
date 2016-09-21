#include<iostream>
using namespace std;
long long arr[202][202];

int main()
{
	int a, b;
	cin >> a >> b;


	arr[0][0] = 1;
	for (int i = 1; i <= b; i++)
	{
		for (int k = 0; k <= a; k++)
		{
			for (int m = 0; m <= k; m++)
			{
				arr[i][k] += arr[i - 1][k - m];
				arr[i][k] %= 1000000000;
			}
		}

	}
	cout << arr[b][a]<<endl;
}