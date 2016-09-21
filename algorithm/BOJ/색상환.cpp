#include<iostream>
using namespace std;
int cnt;
long long arr[1001][1001];

int N, K;
void find(int arr[1000], int now, int nowc)
{
	if (nowc == K)
	{
		cnt++;
		return;
	}

	for (int i = now + 2; i < N; i++)
	{
		if (i != N - 1)
		{
			arr[i] = 1;
			find(arr, i, nowc + 1);
		}
		else
		{
			if (arr[0] != 1)
			{
				arr[i] = 1;
				find(arr, i, nowc + 1);
			}
		}
		arr[i] = 0;
	}



}


long long print(int a, int b)
{
	if (a / 2 < b)
	{
		return 0;
	}
	if (arr[a][b] == 0)
	{
		long long c=0;
		for (int i = 1; i <= a-2; i++)
		{
			c += print(i, b - 1);
			c %= 1000000003;
		}
		arr[a][b] = c;
		return arr[a][b];
	}
	else
	{
		return arr[a][b];
	}
}


int main()
{

	scanf("%d", &N);
	scanf("%d", &K);


	cnt = 0;
	int chkarr[1000] = { 0 };

	if (N / 2 < K)
		printf("0\n");
	else
	{
		/*for (int i = 0; i < N; i++)
		{
			chkarr[i] = 1;
			find(chkarr, i, 1);
			chkarr[i] = 0;
		}*/
		for (int i = 1; i <= N; i++)
			arr[i][1] = i;
		for (int i = 4; i <= N; i++)
		{
			if (i % 2 == 0)
			{
				arr[i][2] = (i / 2)*(i - 1) - i;
			}
			else
			{
				arr[i][2] = i*(i - 1) / 2 - i;
			}
		}


		printf("%lld\n", print(N, K));
	}


}