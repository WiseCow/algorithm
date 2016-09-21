#include<iostream>
using namespace std;
const int mod = 10007;
int arr[1000];

int main()
{
	int a;
	scanf("%d", &a);

	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= a; i++)
		arr[i] = (arr[i - 1] + arr[i - 2]) % mod;

	cout << arr[a] << '\n';


}