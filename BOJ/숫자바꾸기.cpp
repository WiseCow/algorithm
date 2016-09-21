 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int a, b, c;
		cin >> a >> b;

		c = a ^ b;


		int j = 4194304;
		int flag = 0;


		for (int i = 0; j>0; i++)
		{
			if (c / j)
			{
				int tmp = c/j;
				c -= tmp*j;
				flag++;
			}
			j /= 2;
		}
		cout << flag << endl;


	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}