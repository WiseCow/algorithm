#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
bool cmp(const int &a, const int &b)
{
	return  a < b;
}



int main()
{
	int N;
	scanf("%d", &N);
	int arr[10];
	for (int i = 1; i <= N; i++)
	{
		arr[i] = i;
		printf("%d ", i);
	}
	printf("\n");
	while (1)
	{
		int k = N - 1;
		for (; k > 0; k--)
		{
			if (arr[k] < arr[k + 1])
				break;
		}

		if (k == 0)
			break;
		else
		{
			int n = N;
			for (; n > k; n--)
			{
				if (arr[n] > arr[k])
					break;
			}

			int t = arr[n];
			arr[n] = arr[k];
			arr[k] = t;

			for (int i = k+1; i <= N; i++)
			{
				for (int j = k+1; j < N; j++)
				{
					if (arr[j] > arr[j + 1])
					{
						int t = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = t;
					}
				}
			}
			
			for (int i = 1; i <= N; i++)
			{
				printf("%d ", arr[i]);
			}
			printf("\n");

		}
	}

}