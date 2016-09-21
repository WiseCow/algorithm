#include<iostream>
using namespace std;
int main()
{
	int cnt, findmoney;
	cin >> cnt >> findmoney;
	int arr[1001] = { 0 };
	unsigned int res[20000] = { 0 };
	for (int i = 0; i < cnt; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < cnt - 1; i++)
		for (int j = 0; j < cnt - i - 1; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}


	for (int k = 0; k < cnt; k++)
	{
		for (int i = 0; i <= findmoney - arr[k]; i++)
		{
			if (i == 0)
				res[i + arr[k]] = res[i + arr[k]] + 1;

			else
			res[i + arr[k]] = res[i] + res[i + arr[k]];
		}
	}
	cout << res[findmoney] << endl;
}
