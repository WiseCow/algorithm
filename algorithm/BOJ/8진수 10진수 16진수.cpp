#include<cstdio>
char arr[1000];

int main()
{
	scanf("%s", &arr);
	int sum = 0,idx=0;

	if (arr[0] == '0')
	{
		if (arr[1] == 'x')
		{
			idx = 2;
			while (arr[idx] != 0)
			{
				sum *= 16;
				if (arr[idx] >= 'a')
				{
					sum += arr[idx] + 10 - 'a';
				}
				else
				{
					sum += arr[idx] - '0';
				}
				idx++;
			}
		}
		else
		{
			idx = 1;
			while (arr[idx] != 0)
			{
				sum *= 8;
					sum += arr[idx] - '0';
				idx++;
			}
		}
	}
	else
	{
		idx = 0;
		while (arr[idx] != 0)
		{
			sum *= 10;
			sum += arr[idx] - '0';
			idx++;
		}
	}
	printf("%d", sum);
}