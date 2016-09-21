#include<iostream>
#define max(a,b) ((a)>(b))?a:b
using namespace std;
int N, M, arr[1001][1001], D[1001][1001];
int main()
{
	scanf("%d %d", &N, &M);


	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &arr[i][j]);


	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			D[i][j] = max(D[i-1][j]+arr[i][j], max(D[i][j-1] + arr[i][j], D[i - 1][j-1] + arr[i][j]));
		 

	cout << D[N][M] << '\n';
}