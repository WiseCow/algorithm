#include<iostream>

using namespace std;


int main()
{
	int num;
	cin >> num;


	int flag[100001] = { 0, };



	for (int i = 2; i <= num; i++)
	{
		if (flag[i] == 0)
		{
			for (int j = 2; j <= num; j++)
			{
				if (i*j <= num){
					flag[i*j] = 1;
				}

			}
		}
	}

	for (int i = 2; i <= num; i++)
	{
		if (flag[i] == 0)
		{
			cout << i << " ";
		}
	}
}