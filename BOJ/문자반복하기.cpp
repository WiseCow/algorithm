
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		int cnt;
		cin >> cnt;
		char arr[20] = { 0, };

		cin >> arr;
		cout << "#testcase" << (itr + 1) << endl;
		for (int i = 0;i<20; i++)
		for (int j = 0; j < cnt; j++)
		{
			if (arr[i] != 0)
				cout << arr[i];
			else
				break;
		}

		cout << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}