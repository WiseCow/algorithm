#include<iostream>
using namespace std;
int tc;
int arr[1001];
int D[1001];
int main()
{
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++)
	{
		scanf("%d", &arr[i]);
	}

	D[1] = 1;
	for (int i = 1; i <= tc; i++)
	{
		int a = 0;
		for (int j = i - 1; j > 0; j--)
		{
			if (arr[i] > arr[j] && D[j] > a)
				a = D[j];
		}
		D[i] = a + 1;
	}
	int maxx=0;
	for (int i = 1; i <= tc; i++)
		if (D[i]>maxx)
			maxx = D[i];

	cout << maxx << '\n';
}