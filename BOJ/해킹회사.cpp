/*

VCPP, GPP에서 사용

*/

#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		int r, e, c;
		cin >> r >> e >> c;

		cout << "#testcase" << (itr + 1) << endl;

		if (r>e - c)
			cout << "do not advertise" << endl;
		else if (r == (e - c))
			cout << "does not matter" << endl;
		else
			cout << "advertise" << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}