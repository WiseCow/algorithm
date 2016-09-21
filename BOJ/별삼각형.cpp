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
		int cnt;
		int type;
		cin >> cnt>>type;
		
		int star = cnt;
		
		

		cout << "#testcase" << (itr + 1) << endl;
		if (type == 2)
		{
			for (int i = 0; i < cnt; i++)
			{
				for (int j = 0; j < star - i; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}

		}
		else if (type == 1)
		{
			for (int i = 0; i < cnt; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
		}
		else
		{
			for (int i = 0; i < cnt; i++)
			{
				for (int j = 0; j < star - i; j++)
				{
					cout << "  ";
				}
				for (int j = 0; j < 2*i+1; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}

		}

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}