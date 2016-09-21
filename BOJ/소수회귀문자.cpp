 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		bool sosu[1000000];
		for (int i = 2; i < 1000000; i++)
		{
			for (int j = 2; j < 1000000; j++)
			{
				sosu[i*j] = 1;
			}
		}


		cout << sosu << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}