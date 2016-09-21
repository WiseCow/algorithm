#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;


		int max = 0;
		int x, y;

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				int num;
				cin >> num;
				if (num>max)
				{
					x = i; y = j;
					max = num;
				}

			}

		}

		cout << max << endl;
		cout << x+1 <<" "<< y+1 << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}