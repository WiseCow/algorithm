//https://www.acmicpc.net/problem/11727
#include<iostream>
using namespace std;
long long arr[1001];

int main()
{
	int N;
	scanf("%d", &N);

	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 3;
	for (int i = 3; i <= N; i++)
	{
		arr[i] += arr[i - 1];
		arr[i] += arr[i - 2] * 2;
		arr[i] %= 10007;
	}

	cout << arr[N] << endl;



}