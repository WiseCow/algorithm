#include<iostream>
using namespace std;


int main()
{

	int arr[6][6] = { 0 };
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];
	int count = 0;
	while (1)
	{
		int num;
		cin >> num;
		int  chk = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (arr[i][j] == num)
				{
					arr[i][j] = 0;
					chk = 1;
					break;
				}
			}
			if (chk == 1)
				break;
		}
		chk = 0;
		for (int i = 0; i < 5; i++)
		{
			if (arr[i][0] == 0 && arr[i][1] == 0 && arr[i][2] == 0 && arr[i][3] == 0 && arr[i][4] == 0)
				chk++;
			if (arr[0][i] == 0 && arr[1][i] == 0 && arr[2][i] == 0 && arr[3][i] == 0 && arr[4][i] == 0)
				chk++;
		}
		if (arr[0][0] == 0 && arr[1][1] == 0 && arr[2][2] == 0 && arr[3][3] == 0 && arr[4][4] == 0)
			chk++;
		if (arr[4][0] == 0 && arr[3][1] == 0 && arr[2][2] == 0 && arr[1][3] == 0 && arr[0][4] == 0)
			chk++;
		if (chk >= 3)
		{
			cout << count+1 << endl;
			break;
		}
		count++;
	}

}