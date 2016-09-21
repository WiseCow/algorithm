//https://www.acmicpc.net/problem/1790
#include<iostream>
using namespace std;
int arr[20];
int main()
{
	int N, k;

	scanf("%d %d", &N, &k);

	int a = 1;
	for (int i = 1; i <=8 ; i++)
	{
		int t = a;
		a *= 10;
		t = a - t;
		arr[i] = t*i;
		if (i > 1)
		{
			arr[i] += arr[i - 1];
		}
	}

	a = 8;
	for (; a >= 0; a--)
	{
		if (arr[a] < k)
		{
			break;
		}
	}

	int l = 1;
	for (int i = 0; i < a; i++)l *= 10;
	
	int findk = arr[a] + 1;

	a += 1;

	for (; l < l * 10; l++)
	{
		findk += a;
		if (findk > k)
			break;
	}
	findk -= a;
	
	int dif = a-(k - findk);

	int ans = 0;

	int p = 1;
	for (int i = 1; i < dif; i++)p *= 10;

	ans = l / p;
	ans%= 10;
	if (l <= N)
		cout << ans << endl;
	else
		cout << -1 << endl;

}