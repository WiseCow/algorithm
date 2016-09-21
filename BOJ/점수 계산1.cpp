#include<cstdio>
int arr[8][2];
int main()
{
	for (int i = 0; i < 8; i++)
	{
		arr[i][1] = i;
		scanf("%d", &arr[i][0]);
	}
	for (int i = 7; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j][0]>arr[j + 1][0])
			{
				int t = arr[j][0];
				arr[j][0] = arr[j + 1][0];
				arr[j + 1][0] = t;
				t = arr[j][1];
				arr[j][1] = arr[j + 1][1];
				arr[j + 1][1] = t;
			}
		}
	}

	for (int i = 7; i > 3; i--)
	{
		for (int j = 3; j < i; j++)
		{
			if (arr[j][1]>arr[j + 1][1])
			{
				int t = arr[j][0];
				arr[j][0] = arr[j + 1][0];
				arr[j + 1][0] = t;
				t = arr[j][1];
				arr[j][1] = arr[j + 1][1];
				arr[j + 1][1] = t;
			}
		}
	}
	int sum = 0;
	for (int i = 3; i < 8; i++)sum += arr[i][0];
	printf("%d\n", sum);
	for (int i = 3; i < 8; i++)printf("%d ", arr[i][1]+1);
	return 0;
}