#include<iostream>

using namespace std;
int main()
{
	int num;
	cin >> num;
	int arr[10000];
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}



	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num-i-1; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	int res[10000];
	res[0] = arr[0];
	for (int i = 1; i < num; i++)
	{
		res[i] = res[i - 1] + arr[i];
	}
	int flag = 0;
	for (int i = 0; i < num; i++)
	{
		if (arr[i+1] > res[i])
		{
			
			flag = 1;
			cout << res[i]+1 << endl;
			break;
		}
	}
	if (flag == 0)
		cout << res[num - 1]+1<<endl;

}
