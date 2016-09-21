#include<iostream>
using namespace std;
bool visit[1000001];
int arr[3000];

int main()
{
	int tc;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++)
	{
		scanf("%d", &arr[i]);
		visit[arr[i]] = 1;
	}
	int ans = 0;
	for (int i = 0; i < tc; i++)
	{
		for (int j = i + 1; j < tc; j++)
		{
			int dif = arr[j] - arr[i];
			int sum = 0;
			if (arr[j] + dif <= 1000000 && visit[arr[j] + dif] == 1)
			{
				sum = arr[j] + arr[i];
				for (int l = arr[j] + dif; l <= 1000000; l += dif)
				{
					if (visit[l] == 1)
						sum += l;
					else
						break;
				}
			}



			if (ans < sum)
				ans = sum;
		}
	}


	printf("%d\n", ans);
	return 0;


}