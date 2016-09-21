#include<cstdio>
char arr[2][81];
int res[81];
int idx[2], c, mx;
int main()
{
	scanf("%s%s", &arr[0], &arr[1]);
	for (int j = 0; j < 2; j++)	for (int i = 0; arr[j][i]; i++)	idx[j] = i;

	mx = idx[0]>idx[1] ? idx[0] : idx[1];

	for (int i = 0; i <= mx; i++)
	{
		int sum = c;
		if (idx[0] >= 0)
			sum += arr[0][idx[0]] - '0';
		if (idx[1] >= 0)
			sum += arr[1][idx[1]] - '0';
		if (sum == 3)
		{
			c = 1;
			res[mx - i] = 1;
		}
		else if (sum == 2)
		{
			c = 1;
			res[mx - i] = 0;
		}
		else if (sum == 1)
		{
			c = 0;
			res[mx - i] = 1;
		}
		else
		{
			c = 0;
			res[mx - i] = 0;
		}
		idx[0]--;
		idx[1]--;
	}
	bool chk = 0;
	if (c == 1)
	{
		printf("1");
		chk = 1;
	}
	for (int i = 0; i <= mx; i++)
	{
		if (!chk)
		{
			if (!res[i])
				continue;
			else
			{
				chk = 1;
			}
		}
		printf("%d", res[i]);
	}
	if (!chk)
		printf("0");


	return 0;
}