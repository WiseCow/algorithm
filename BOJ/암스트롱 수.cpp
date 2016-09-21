

#include <iostream>
using namespace std;
int main()
{

	int nCount=1;		/* 문제의 테스트 케이스 */



	for (int itr = 0; itr<nCount; itr++)
	{
		

		cout << "#testcase" << (itr + 1) << endl;

		for (int i = 1; i <= 10000; i++)
		{
			if (i / 1000 >= 1){
				if (((i*i) - i) % 1000 == 0)
				{
					cout << i << endl;
				}
			}
			else if (i / 100 >= 1)
			{
				if (((i*i) - i) % 100 == 0)
				{
					cout << i << endl;
				}
			}
			else if (i / 10 >= 1)
			{
				if (((i*i) - i) % 10 == 0)
				{
					cout << i << endl;
				}
			}

			

		}

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}