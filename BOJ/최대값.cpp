 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		
		int arr[100];
		int _max=0, flag;

		for (int i = 0; i < 4; i++)
		{
			cin >> arr[i];
			if (arr[i]>_max)flag = i, _max = arr[i];
		}
		cout << "#testcase" << (itr + 1) << endl;

		cout << arr[flag] << "\n" << flag + 1 << endl;

		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}