 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		char arr[10];
		cin >> arr;
		int max = 0;
		int cnt = 1;
		for (int i = 1; i <= 8; i++)
		{
			if (cnt > max)
				max = cnt;
			if (i == 8)
				break;
			if (arr[i - 1] == arr[i])
				cnt++;
			else
			{
				cnt = 1;

			}

		}
		cout << max << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}