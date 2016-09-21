#include<iostream>
#define max(a,b) ((a)>(b))?a:b
using namespace std;
int tc;
int arr[301], D[301];

int main()
{
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++)
		scanf("%d", &arr[i]);

	D[1] = arr[1];
	D[2] = D[1] + arr[2];

	for (int i = 3; i <=tc; i++)
	{
			D[i] = max(D[i - 2] + arr[i], D[i - 3] + arr[i] + arr[i - 1]);
	}

	cout << D[tc] << endl;


}