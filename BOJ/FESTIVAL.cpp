#include<iostream>

using namespace std;

int main()
{
	int C;
	cin >> C;
	for (int itr = 0; itr < C; itr++)
	{
		int N, L;

		cin >> N >> L;
		int arr[10000];
		double res[10000] = { 0 };

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		int min = 100000;
		for (int i = 0; i <= N - L; i++)
		{
			int sum = 0;
			for (int j = i; j < i + L; j++)
			{
				sum += arr[j];
			}
			if (sum < min)
				min = sum;
		}
		res[L] = min;
		int tmp = L + 1;
		while (tmp < N)
		{
			min = 100000;
			for (int i = 0; i < N - tmp; i++)
			{
				int sum = 0;
				for (int j = i; j < i + tmp; j++)
				{
					sum += arr[j];
				}
				if (sum < min)
					min = sum;
			}
			res[tmp++] = min;
		}
		double resmin = 1000000.00000000000;
		for (int i = L; i <= N; i++)
		{
			res[i] /= i;
			if (resmin>res[i]&&res[i]!=0)
				resmin = res[i];
		}
		printf("%.11f\n",resmin);
	}
}