//https://algospot.com/judge/problem/read/TRIANGLEPATH

#include<iostream>


using namespace std;



int main()
{
	int tc;
	cin >> tc;


	for (int k = 0; k < tc; k++)
	{
		int cnt;
		int arr[101][101];
		cin >> cnt;

		for (int i = 0; i < cnt;i++)
		for (int j = 0; j < i+1; j++)
			cin >> arr[i][j];
	
		for (int r = cnt - 1; r > 0;r--)
		for (int j = r - 1; j >= 0; j--)
		{
			if (arr[r][j]>arr[r][j + 1])
				arr[r - 1][j] += arr[r][j];
			else
				arr[r - 1][j] += arr[r][j+1];

		}

		cout << arr[0][0] << endl;


	}
	return 0;
}