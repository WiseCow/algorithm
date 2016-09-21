#include <iostream>
using namespace std;
#define INF -1987654321
int N, maxmax, maxmax1;
int arr[100001];
int DPTable[100001];
int DPTable1[100001];

int Max(int a, int b) { return a > b ? a : b; }
int RecursionDP(int pos)
{
	if (pos == N)
	{
	
		return arr[pos];
	}

	int& ret = DPTable[pos];
	if (ret != INF)
		return ret;
	ret = arr[pos];

	ret = Max(ret, RecursionDP(pos + 1) + arr[pos]);
	maxmax = Max(maxmax, ret);

	return ret;
}
int RecursionDP1(int pos)
{
	if (pos == 1)
		return arr[pos];

	int& ret = DPTable1[pos];
	if (ret != INF)
		return ret;

	ret = arr[pos];

	ret = Max(ret, RecursionDP1(pos - 1) + arr[pos]);
	maxmax1 = Max(maxmax1, ret);

	return ret;
}


int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 0; i <= N; i++)
		DPTable[i] = INF;
	for (int i = 0; i <= N; i++)
		DPTable1[i] = INF;


	maxmax = arr[N];
	maxmax1 = arr[1];
	RecursionDP(1);
	RecursionDP1(N);
	cout << maxmax << endl;
	cout << maxmax1 << endl;


	return 0;
}

