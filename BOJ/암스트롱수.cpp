/*

VCPP, GPP에서 사용

*/

#include <iostream>
using namespace std;
int main()
{

	int nCount=1;		/* 문제의 테스트 케이스 */

	//cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		
		cout << "#testcase" << (itr + 1) << endl;
		for (int i = 100; i < 1000; i++)
		{
			int a=i,x, y, z;
			x = a / 100;
			a -= x * 100;
			y = a / 10;
			a -= y * 10;
			z = a;
			if (x*x*x + y*y*y + z*z*z == i)
				cout << i << endl;
		}
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}