#include<cstdio>
#include<algorithm>
using namespace std;
int  D1, D2, sum;
bool sec[2001][2001];

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		gcd(b, a%b);
}
int main()
{
	scanf("%d%d", &D1, &D2);
	sum = 1;
	for (int i = D1; i <= D2; i++)
	{

		for (int j = 1; j < i; j++)
		{
			int k = gcd(j, i);
			if (!sec[j / k][i / k])
			{
				sum++;
				sec[j / k][i / k] = true;
			}
		}
	}
	printf("%d\n", sum);
}