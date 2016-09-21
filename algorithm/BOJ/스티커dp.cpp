#include<iostream>
#include<cstring>
#define max(a,b) ((a)>(b))?a:b
using namespace std;
int D[100001][3];
int arr[100001][2];
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{
		int n;
		scanf("%d", &n);
		memset(D, 0, sizeof(D));
	
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i][0]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i][1]);

		D[1][0] = D[2][1] = arr[1][0];
		D[1][1] = D[2][0] = arr[1][1];
		D[2][1] += arr[2][1];
		D[2][0] += arr[2][0];
		D[2][2] = max(D[1][0], D[1][1]);
		for (int i = 3; i <= n; i++)
		{
			D[i][0] = max(D[i - 1][1] + arr[i][0], max(D[i - 1][2] + arr[i][0], D[i - 2][0] + arr[i][0]));
			D[i][1] = max(D[i - 1][0] + arr[i][1], max(D[i - 1][2] + arr[i][1], D[i - 2][1] + arr[i][1]));
			D[i][2] = max(D[i - 1][0],D[i-1][1]);
		}

		int maxx = max(D[n][0], max(D[n][1], D[n][2]));
		cout << maxx << '\n';
	}



}