
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)return a;
	else gcd(b, a%b);

}

int main()
{

	int nCount;

	cin >> nCount;

	for (int itr = 0; itr<nCount; itr++)
	{
		long long a, b;

		cin >> a >> b;

		long long  ans = gcd(a, b);
		a /= ans;
		b /= ans;

		long long res = a*b;
		cout << "#testcase" << (itr + 1) << endl;

		cout << res << endl;

	}

	return 0;

}