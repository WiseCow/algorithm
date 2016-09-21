//https://www.acmicpc.net/problem/1463
#include<iostream>
using namespace std;
int arr[1000001] = { 0 };

int main()
{
	int a;
	scanf("%d",&a);

	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	for (int i = 5; i <= a; i++)
	{
		int a = arr[i - 1];
		if (i % 2 == 0)
		{
			if(arr[i / 2]<a)
				a = arr[i / 2];
		}
		if (i % 3 == 0)
		{
			if(arr[i / 3]<a)
			a = arr[i / 3];
		}

		arr[i] = a + 1;

	}

	cout << arr[a] << endl;


}