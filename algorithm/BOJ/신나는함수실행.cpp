#include<iostream>
using namespace std;

int arr[21][21][21];

int w(int a, int b, int c)
{
	if (a < 0)a = 0;
	if (b < 0)b = 0;
	if (c < 0)c = 0;
	if (a > 20)a = 20;
	if (b > 20)b = 20;
	if (c > 20)c = 20;
	int result = 0;


	if (arr[a][b][c] != 0)
		return arr[a][b][c];

	if (a <= 0 || b <= 0 || c <= 0)
	{
		result= 1;
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		result = w(20, 20, 20);
	}
	else if (a < b && b < c)
	{
		result =w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else
	{
		result = (w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1));
	}

	arr[a][b][c] = result;
	return result;
}

int main()
{
	int a, b, c;
	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);

		if (a == -1 && b == -1 && c == -1)
			break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
}