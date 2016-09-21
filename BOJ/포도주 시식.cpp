#include<iostream>
#define max(a,b) ((a)>(b))?a:b
using namespace std;
long long D[10001];
int arr[10001];
int n;
int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);


	D[1] = arr[1];
	D[2] = arr[1]+arr[2];

	for (int i = 3; i <= n; i++)
	{
		D[i] = max(D[i - 1], max(D[i - 2] + arr[i], D[i - 3] + arr[i - 1] + arr[i]));
	}

	cout << D[n] << '\n';


}