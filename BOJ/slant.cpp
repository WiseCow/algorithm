 

#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int x1, y1, x2, y2;
		cin>> x1 >> y1;
		cin>> x2 >> y2;

		if (x1 < x2)
		{
			x1 = x2 - x1;
			y1 = y2 - y1;
		}
		else
		{
			x1 = x1 - x2;
			y1 = y1 - y2;
		}
		int i;
		for ( i = 0; x1*i < y1; i++);
		cout << i << " "<< y2-x2*i<< endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}