#include<iostream>
using namespace std;
int main()
{
	int col, row;
	scanf("%d %d", &row, &col);

	char arr[101][101];
	for (int i = 0; i < row; i++)
	{
		cin >> arr[i];
	}
	
	int chcol, chrow;
	scanf("%d %d", &chrow, &chcol);

	for (int i = 0; i < row; i++)
	{
		int p = col;
		for (int k = col - 1; k >= 0; k--)
		{
			arr[i][p++] = arr[i][k];
		}
		arr[i][p] = 0;
	}

	int p = row - 1;
	for (int i = row; i < row * 2; i++)
	{
		for (int k = 0; k <= col * 2; k++)
		{
			arr[i][k] = arr[p][k];
		}
		p--;
	}

	if (arr[chrow-1][chcol-1] == '#')
		arr[chrow-1][chcol-1] = '.';
	else
		arr[chrow-1][chcol-1] = '#';


	for (int i = 0; i < row * 2; i++)
	{
		cout << arr[i] << endl;
	}
}