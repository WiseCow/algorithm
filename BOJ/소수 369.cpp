#include<iostream>

using namespace std;
int arr[1000000] = { 0 };
int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 2; i < M+1; i++)
	{
		for (int j = 2; j*i <M + 1; j++)
			arr[j*i] = 1;
	}
	int flag = 0;
	arr[0] = 1;
	arr[1] = 1;
	for (int k = K+1; k < M; k += N)
	{
		if (arr[k] == 0)
			flag++;
	}
	cout << flag << endl;
}