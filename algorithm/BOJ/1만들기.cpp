#include<iostream>
#define min(a,b) ((a)>(b))?(b):(a)
using namespace std;
int arr[1000001];
const int INF = 987654321;

int main()
{
	int a;
	scanf("%d", &a);

	for (int i = 0; i <= a; i++)
	{
		arr[i] = 987654321;
	}
	arr[1] = 0;
	for (int i = 1; i < a; i++)
	{
		arr[i + 1] = min(arr[i + 1], arr[i] + 1);
		if(i*2<=1000000)
		arr[i*2] = min(arr[i*2], arr[i] + 1);
		if(i*3<=1000000)
		arr[i*3] = min(arr[i*3], arr[i] + 1);

	}


	cout << arr[a] << '\n';
}