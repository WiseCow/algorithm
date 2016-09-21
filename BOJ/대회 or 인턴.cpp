#include<iostream>
using namespace std;
int N, M, K;

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	int tmpn, tmpm,mkn,need;

	mkn = N / 2;
	tmpn = N % 2;
	if(mkn<=M)
		tmpm = M - mkn;
	else
	{
		int a = mkn-M;
		mkn = M;

		tmpn += a * 2;
		tmpm = 0;
	}
	need = K - tmpn - tmpm;

	if (need <= 0)
		cout << mkn << '\n';
	else
	{
		int p = need / 3;
		if (need % 3 > 0)
			p++;

		cout << mkn - p << '\n';
	}

}