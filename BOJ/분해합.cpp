#include<cstdio>
int input,k=1000000;
int main()
{
	scanf("%d", &input);
	int t = 1, za = 0;
	for (int i = 7; i >= 1; i--)
	{
		if (input / k)
		{
			t = k;
			za = i;
			break;
		}
		k /= 10;
	}
	int mini = input - za * 10;
	int plus = 0, tt = mini;
	for (int i = za; i > 0; i--)
	{
		plus += tt / k;
		tt %= k;
		k /= 10;
	}
	if (mini <= 0)
	{
		mini = 0;
		plus = 0;
	}
	bool chk = 0;
	for (int i = mini; i < input; i++)
	{
		
		if (i + plus == input)
		{
			printf("%d", i);
			chk = 1;
			break;
		}
		if (!((i + 1) % 1000000))
			plus -= 53;
		else if (!((i + 1) % 100000))
			plus -= 44;
		else if (!((i + 1) % 10000))
			plus -= 35;
		else if (!((i + 1) % 1000))
			plus -= 26;
		else if (!((i + 1) % 100))
			plus -= 17;
		else if (!((i + 1) % 10))
			plus -= 8;
		else if (!((i + 1) % 1))
			plus++;
	}
	if (!chk)
		printf("0");

	return 0;
}