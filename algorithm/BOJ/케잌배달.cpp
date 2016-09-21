//https://www.acmicpc.net/problem/2159

#include<iostream>
using namespace std;
long long arr[100000][5];
long long dx[5] = { -1,0,1,0,0 };
long long dy[5] = { 0,-1,0,1,0 };
long long _abs(long long a)
{
	return a >= 0 ? a : -a;
}

int main()
{
	long long tc;
	scanf("%lld", &tc);
	long long sx, sy;
	scanf("%lld %lld", &sx, &sy);

	for (long long i = 0; i < tc; i++)
	{
		long long x, y;
		scanf("%lld %lld", &x, &y);

		if (i == 0)
		{
			for (long long k = 0; k < 5; k++)
			{
				arr[0][k] = _abs(sx - (x + dx[k])) + _abs(sy - (y + dy[k]));
			}
		}
		else
		{

			for (long long k = 0; k < 5; k++)
			{
				for (long long j = 0; j < 5; j++)
				{
					long long a = arr[i - 1][j] + _abs(sx + dx[j] - (x + dx[k])) + _abs(sy + dy[j] - (y + dy[k]));

					if (arr[i][k] == 0)
						arr[i][k] = a;
					else if (arr[i][k]>a)
						arr[i][k] = a;

				}
			}
		}
		sx = x;
		sy = y;

	}
	long long  mini = 4611686018427387904;
	for (long long i = 0; i < 5; i++)
	{
		if (mini > arr[tc - 1][i])
		{
			mini = arr[tc - 1][i];
		}
	}

	cout << mini << '\n';





}