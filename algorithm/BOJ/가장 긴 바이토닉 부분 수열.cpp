#include<iostream>
using namespace std;
int UD[1001];
int DD[1001];
int arr[1001];
int tc;
int main()
{

	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++)
		scanf("%d", &arr[i]);

	UD[1] = 1;


	for (int i = 2; i <= tc; i++)
	{
		int a = 0;
		for (int j = i - 1; j > 0;j--)
		{
			if (arr[i] > arr[j] && UD[j] > a)
				a = UD[j];
		}
		UD[i] = a+1;
	}

	DD[tc] = 1;
	for (int i = tc; i > 0; i--)
	{
		int a = 0;
		for (int j = i + 1; j <= tc; j++)
		{
			if (arr[i] > arr[j] && DD[j] > a)
				a = DD[j];
		}
		DD[i] = a + 1;
	}




	int maxx = 0;
	for (int i = 1; i <= tc; i++)
	{
		if (maxx < UD[i] + DD[i])
			maxx = UD[i] + DD[i];
	}
	cout << maxx-1 << '\n';
}