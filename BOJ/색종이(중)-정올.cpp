#include<iostream>
using namespace std;

void find(int(*arr)[102], int x, int y)
{
	int flag = 0;
	if (x - 1 > 0 && arr[x - 1][y] >= 1)flag++;
	if (y - 1 > 0 && arr[x][y - 1] >= 1)flag++;
	if (x + 1 < 101 && arr[x + 1][y]>=1)flag++;
	if (y + 1 < 101 && arr[x][y + 1] >= 1)flag++;
	if (x - 1 > 0 && y - 1 > 0 && arr[x - 1][y - 1] >= 1)flag++;
	if (x - 1 > 0 && y + 1 < 101 && arr[x - 1][y + 1] >= 1)flag++;
	if (x + 1 <101 && y + 1 < 101 && arr[x + 1][y + 1] >= 1)flag++;
	if (x + 1 <101 && y - 1 > 0 && arr[x + 1][y - 1] >= 1)flag++;

	if (flag < 8)arr[x][y] = 2;
}

int main()
{
	int cnt;
	cin >> cnt;
	int arr[102][102] = { 0 };
	for (int i = 0; i < cnt; i++)
	{
		int a, b;
		cin >> b >> a;

		for (int k = 0; k < 10; k++)
		{
			for (int l = 0 ; l < 10; l++)
			{
				if (a+k<=101&&b+l<=101)
				arr[a + k][b + l] = 1;

			}
		}
	}
	int sum=0;
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (arr[i][j] == 1)
			{
				find(arr, i, j);
			}
		}
	}
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			
				if (arr[i][j] == 2)
				{
					sum++;
					if (arr[i + 1][j] == 2 && arr[i][j + 1] == 2)
						sum++;
					else if (arr[i + 1][j] == 2 && arr[i][j - 1] == 2)
						sum++;
					else if (arr[i - 1][j] == 2 && arr[i][j + 1] == 2)
						sum++;
					else if (arr[i - 1][j] == 2 && arr[i][j - 1] == 2)
						sum++;

				}
			
		}
	}

	cout << sum<<endl;
	return 0;




}