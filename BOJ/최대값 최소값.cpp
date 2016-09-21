#include <iostream>
#include<string.h>
#include<math.h>

using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int cnt;
		cin >> cnt;
		int min = 1000;
		int max = 0;
		for (int i = 0; i < cnt; i++)
		{
			int a = 0;
			cin >> a;
			if (a>max)
				max = a;
			if (a < min)
				min = a;
		}
		cout << max - min << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}