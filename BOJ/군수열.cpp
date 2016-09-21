#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int c;
		cin >> c;
		int sum = 0;
		int sumsum = 0;
		for (int i = 1; i <= c; i++)
			sum += i, sumsum+=sum;
		cout << sumsum << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}