#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int num;
		cin >> num;
		int flag = 0;
		for (int i = 1; i < 1000; i++)
		{
			if (num%i == 0)
				flag++;
		}
		if (flag % 2 == 0)
			cout << "no" << endl;
		else
			cout << "yes" << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}