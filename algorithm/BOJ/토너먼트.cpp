#include<iostream>
using namespace std;
bool maxx(int a, int b)
{
	return a > b ? 1 : 0;
}
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (maxx(b, c))
	{
		int tmp = b;
		b = c;
		c = tmp;
	}

	int boa = 2;
	for (; boa < a; boa *= 2);


	int term = 2;
	int cnt = 0;
	bool chk = 0;


	while (term <= boa)
	{
		cnt++;
		int tb = (b - 1) / term;
		int tc = (c - 1) / term;
		


		if (tb == tc)
		{
			chk = 1;
			break;
		}
		term *= 2;
	}


	if (chk == 1)
	{
		cout << cnt << endl;
	}
	else
		cout << -1 << endl;




}