

#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		int gugu;
		cin >> gugu;

		cout << "#testcase" << (itr + 1) << endl;

		for (int i = 1; i < 10; i++)
			cout << gugu << "*" << i << "=" << gugu*i << endl;
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}