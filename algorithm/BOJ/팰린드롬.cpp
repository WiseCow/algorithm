#include<iostream>
using namespace std;
int N, arr[2001], M;
int D[2001][2001];
int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
		D[i][i] = 1;
		for (int l = 1; l < i; l++)
		{
			if (l == 1)
			{
				if (arr[i] == arr[i - l])
					D[i][i - l] = 1;
			}
			else
			{
				if (D[i - 1][i - l + 1] == 1)
				{
					if (arr[i] == arr[i - l])
						D[i][i - l] = 1;
				}
			}		
		}
	}
	
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		cout << D[b][a] << '\n';
	}
	return 0;
}