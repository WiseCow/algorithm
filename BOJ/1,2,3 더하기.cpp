//https://www.acmicpc.net/problem/9095
#include<iostream>
using namespace std;
int arr[100];

int main()
{
	int tc;
	cin >> tc;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 4; i < 12; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	for (int i = 0; i < tc; i++)
	{
		int input;
		scanf("%d", &input);
		cout << arr[input] << endl;
	}
}