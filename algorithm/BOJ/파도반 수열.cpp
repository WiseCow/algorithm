#include<iostream>
using namespace std;
long long arr[102];

long long func(int a)
{
	if (arr[a] != 0)
	{
		return arr[a];
	}
	else
	{
		arr[a] = func(a-1)+func(a - 5);
		return arr[a];
	}
}
int main()
{
	int tc;
	cin >> tc;
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	arr[6] = 3;
	arr[7] = 4;
	arr[8] = 5;
	for (int itr = 0; itr < tc; itr++)
	{
		int k;
		cin >> k;

		printf("%lld\n", func(k));
	}

}