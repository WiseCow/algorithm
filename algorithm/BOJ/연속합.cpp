#include<iostream>
using namespace std;
int tc;
int arr[100001], D[100001];
int main()
{
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++)
		scanf("%d", &arr[i]);
		
	D[1] = arr[1];
	for (int i = 2; i <= tc; i++)
	{
		D[i] = arr[i];
		if (D[i - 1] + arr[i] > arr[i])
			D[i] = arr[i] + D[i - 1];
	}

	int maxx = D[1];
	for (int i =2; i <= tc; i++)
		if (D[i] > maxx)
			maxx = D[i];


	cout << maxx << '\n';

}