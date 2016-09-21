#include<iostream>
using namespace std;
int main()
{
	int tc;
	cin >> tc;


	for (int i = 0; i < tc; i++)
	{
		char arr[100];
		cin >> arr;
		int b = 0;
		while (arr[b++]!= 0);

		int a = arr[b - 2] - '0';
		if (a % 2 == 0)
			cout << "even" << endl;
		else
			cout << "odd" << endl;
	}

}