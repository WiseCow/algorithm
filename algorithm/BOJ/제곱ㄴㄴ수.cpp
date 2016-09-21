#include<iostream>
using namespace std;
long long je[1000001];
bool chk[1000001];

bool so[1000001];
int main()
{
	long long min, max;

	scanf("%lld %lld", &min, &max);

	int p = 0;

	so[1] = 1;
	so[2] = 0;
	for (long long i = 2; i <= 1000000; i++)
	{
		for (long long j = 2; j*i <= 1000000; j++)
		{
			so[i*j] = 1;
		}
	}
	for (long long i = 2; i*i <= max; i++)
	{
		if (so[i] == 0)
			je[p++] = i*i;
	}

	for (long long k = 0; k < p; k++)
	{
		long long l = min / je[k] * je[k];
		while (l%je[k] != 0)
			l++;


		for (; l <= max; l += je[k])
		{
			if (l >= min)
				chk[l - min] = 1;
		}
	}


	long long a = 0;
	for (long long i = 0; i <= max - min; i++)
	{
		if (chk[i] == 0)
			a++;
	}

	printf("%lld\n",a);

}