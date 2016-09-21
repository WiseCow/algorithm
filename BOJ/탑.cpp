
#include<iostream>
using namespace std;
int arr[500000] = { 0 };
int res[500000] = { 0 };
int main()
{
	int cnt;
	cin >> cnt;
	for (int i = 1; i <= cnt; i++)
		cin >> arr[i];


	for (int i = 0; i <= cnt; i++)
	{
		for (int j = i + 1; j <= cnt; j++)
		{
			if (arr[j]>arr[i])
				break;
			else
			{
				res[j] = i;
			}
		}
	}

	for (int i = 1; i <= cnt; i++)
	{
		cout << res[i] << " ";
	}
}