 

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
		
		if (a % 2 == 0 && b % 2 == 0)
		{
			cout << "even+even=even" << endl << "even*even=even" << endl;
		}
		else if (a % 2 == 0)
		{

			cout << "even+odd=odd" << endl << "even*odd=even" << endl;
		}
		else if (b % 2 == 0)
		{
			cout << "odd+even=odd" << endl << "odd*even=even" << endl;
		}
		else
		{
			cout << "odd+odd=even" << endl << "odd*odd=odd" << endl;

		}
		

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}