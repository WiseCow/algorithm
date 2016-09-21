 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int cnt, find;
		cin >> cnt >> find;
		char arr[101] = { 1, };

		for (int i = 2; i <= cnt; i++)
		{
			for (int j = 1;; j++)
			{
				if (i*j > 100)
					break;
				if (arr[i*j] == 0)
					arr[i*j] = 1;
				else
					arr[i*j] = 0;
			}
		}

		if (arr[find] == 0)
			cout << 1 << endl;
		else
			cout << 0 << endl; 

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}