#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)return a;
	else return gcd(b, a%b);
}
int main()
{
	int num;
	cin >> num;
	int arr[100000], point = 0;
	for (int i = 2; i <= num; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (gcd(i, j) == 1)
			{
				arr[point++] = j;
				arr[point++] = i;
			}
		}
	}
	for (int i = 0; i < point-1; i+=2)
	{
		int min = i;

		for (int j = i + 2; j < point; j += 2)
		{
			if (arr[j + 1] * arr[min] > arr[min + 1] * arr[j])
				min = j;
		}
		int tmp1;
		tmp1 = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp1;
		tmp1 = arr[i + 1];
		arr[i + 1] = arr[min + 1];
		arr[min + 1] = tmp1;
	}
	cout << "0/1" << endl;
	for (int i = 0; i < point; i += 2)
		cout << arr[i] << "/" << arr[i + 1] << endl;

	cout << "1/1" << endl;
}