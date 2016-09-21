#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	int arr[10001];
	
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}

	int k = N-1;
	for (; k > 0; k--)
	{
		if (arr[k] > arr[k + 1])
			break;
	}

	if (k == 0)
		printf("-1\n");
	else
	{
		int p = N;
		for (; p > k; p--)
		{
			if (arr[k] > arr[p])
				break;
		}

		int t = arr[p];
		arr[p] = arr[k];
		arr[k] = t;
		priority_queue<int> q;
		for (int i = k + 1; i <= N; i++)
		{
			q.push(arr[i]);
		}
		for (int i = 1; i <= k; i++)
		{
			printf("%d ", arr[i]);
		}

		while (q.size())
		{
			printf("%d ", q.top());
			q.pop();
		}
	}

	return 0;
}