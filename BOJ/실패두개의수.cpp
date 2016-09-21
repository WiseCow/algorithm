 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int a, b;
		cin >> a >> b;
		int c = a*b;

		int sqr;
		for (sqr = 1;; sqr++)
		{
			if (sqr*sqr > c)
				break;
		}
		while (1)
		{
			if (c%sqr == 0)
				break;
			else
				sqr++;
		}
		int sqr2 = sqr - 1;
		while (1)
		{
			if (c%sqr2 == 0)
				break;
			else
				sqr2--;
		}

		cout << sqr2 << " " << sqr << endl;


	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}