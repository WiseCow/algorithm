//https://www.acmicpc.net/problem/11052
#include<iostream>
using namespace std;
int rde[1001];
int mon[10001];
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &mon[i]);
	}


	for (int i = 1; i <= N; i++)
	{
		rde[i] = mon[i];
		int a=0;
		for (int j = i - 1; j > 0; j--)
		{
			int l = rde[i-j] + mon[j];
			if (a < l)
				a = l;
		}
		if (rde[i] < a)
			rde[i] = a;
	}



	cout << rde[N] << endl;
}