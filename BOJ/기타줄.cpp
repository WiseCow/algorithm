#include<iostream>
#define min(a,b) ((a)<(b))?a:b
using namespace std;
int N, M;
int main()
{
	scanf("%d %d", &N, &M);

	int pm = 0, nm = 0;
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (i==1)
		{
			pm = a;
			nm = b;
		}
		pm = min(pm, a);
		nm = min(nm, b);
	}
	int a = N;
	long long money = 0,t1,t2,t3;

	money += N / 6 * pm;
	N = N % 6;
	money += N*nm;
	t1 = money;

	money = 0;
	N = a;
	money += (N / 6 + 1) * pm;
	t2 = money;

	money = 0;
	N = a;
	money += nm*N;
	t3 = money;

	money = min(t1, min(t2,t3));

	cout << money << '\n';
	return 0;
}