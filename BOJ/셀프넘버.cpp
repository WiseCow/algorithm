#include<cstdio>
bool self[10001];
int main()
{
	for (int i = 1; i <= 10000; i++)
	{
		int c = 1;
		if (i >= 10000)
			c = 10000;
		else if (i >= 1000)
			c = 1000;
		else if (i >= 100)
			c = 100;
		else if (i >= 10)
			c = 10;

		int k = i,t=i;
		for (; c >= 1; c /= 10)
		{
			k += t / c;
			t %= c;
		}
		self[k] = 1;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (!self[i])
			printf("%d\n", i);
	}
}