//https://www.acmicpc.net/problem/10000
#include<iostream>
using namespace std;

int main()
{
	int itr = 0;

	cin >> itr;

	int arr1[1000], arr2[1000];
	int chk[1000] = { 0 };
	for (int i = 0; i < itr; i++)
	{
		cin >> arr1[i];
	}
	for (int i = 0; i < itr; i++)
	{
		cin >> arr2[i];
		chk[i] = arr1[i]-arr2[i];
	}

	int sum = 0;

	while (1)
	{
		int up = 0;

		int flag = 0;
		for (int i = 0; i < itr; i++)
		{
			int flagchk;
			if (chk[i] > 0)
			{
				flagchk = 1;
			}
			else if (chk[i] == 0)
			{
				flagchk = 0;
				flag = 0;
				continue;
			}
			else
			{
				flagchk = -1;
			}

			if (flag != flagchk)
			{
				if (flagchk > 0)
					chk[i] -= 1;
				else
					chk[i] += 1;
				flag = flagchk;
				up++;
				/*for (int i = 0; i < itr; i++)
					cout << chk[i] << " ";*/
			}
			else
			{
				if (flagchk > 0)
					chk[i] -= 1;
				else
					chk[i] += 1;
				flag = flagchk;
			}
			//cout << endl;
		}
		if (up == 0)
			break;
		sum += up;
	}
	cout << sum << endl;



}