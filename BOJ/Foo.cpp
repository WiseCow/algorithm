 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		char foo[300];
		cin >> foo;

		int a = strlen(foo);

		for (int i = 0; i < a - 2; i++)
		{
			if (foo[i] == 'F' && foo[i+1] == 'O' &&foo[i+2] == 'O')
			{
				foo[i] = 'O';
				foo[i+1] = 'O';
				foo[i+2] = 'F';

			}
		}
		cout << "#testcase" << (itr + 1) << endl;
		cout << foo<<endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}