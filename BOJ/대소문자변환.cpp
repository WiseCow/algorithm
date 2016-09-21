 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		char arr[1000];
		cin >> arr;

		for (int i = 0; arr[i] != 0; i++)
		{
			if (arr[i] < 91)
				printf("%c", (arr[i] + 32));
			else
				printf("%c", (arr[i] - 32));
		}
		cout << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}