#include<iostream>
using namespace std;
int arr[50001];
int amax[50001];
int tra[500001][4];
int cnt;
int tmax;
int tc;
//void findmax(int idx, int num, int sum)
//{
//	sum += amax[idx];
//	if (num == 3)
//	{
//		if (cnt < sum)
//		{
//			cnt = sum;
//		}
//		return;
//	}
//
//
//	for (int i = idx + tmax; i <= tc - tmax + 1; i++)
//	{
//		findmax(i, num + 1, sum);
//	}
//}


int main()
{
	
	scanf("%d", &tc);


	for (int i = 1; i <= tc; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	scanf("%d", &tmax);

	int a = 0;
	for (int i = 1; i <= tmax; i++)
	{
		a += arr[i];
	}
	amax[1] = a;

	for (int i = 2; i <= tc-tmax+1; i++)
	{
		amax[i] = amax[i - 1] - arr[i - 1] + arr[tmax + i - 1];
	}



	for (int i = 1; i <= tc; i++)
	{
		for (int q = 1; q < 4; q++)
		{
			tra[i][q] = tra[i-1][q];
			if (i >= tmax)
			{
				if (tra[i][q] < tra[i - tmax][q - 1]+amax[i-1])
				{
					tra[i][q] = tra[i - tmax][q - 1] + amax[i-1];
				}
			}
		}
	}





	cout << tra[tc][3] << "\n";

	return 0;
}
