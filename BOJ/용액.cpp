#include<iostream>
using namespace std;
int _abs(int i)
{
	if (i < 0)
		return -i;
	else
		return i;
}
int main()
{
	int cnt;
	cin >> cnt;
	int arr[100000];
	for (int i = 0; i < cnt; i++)
	{
		cin >> arr[i];
	}
	int min = _abs(arr[cnt - 1] + arr[0]);
	int x = 0, y = cnt - 1;
	int minx, miny;
	while (1)
	{
		if (x == y)
			break;
		if (arr[y] + arr[x]>0)
		{
			if (min >= _abs(arr[y] + arr[x]))
			{
				min = _abs(arr[y] + arr[x]);
				minx = x, miny = y;
			}
			y--;

		}
		else if (arr[y] + arr[x] == 0)
		{
			min = 0;
			minx = x, miny = y;
			break;
		}
		else
		{
			if (min >= _abs(arr[y] + arr[x]))
			{
				min = _abs(arr[y] + arr[x]);
				minx = x, miny = y;
			}
			x++;
		}
	}
	cout << arr[minx] << " " << arr[miny] << endl;
}