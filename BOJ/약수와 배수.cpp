/*

VCPP, GPP에서 사용

*/

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
		int arr[100];
		for (int i = 0; i < cnt; i++)
		{
			cin >> arr[i];
		}
		int num;
		cin >> num;
		int sum = 0;
		int sum1 = 0;

		for (int i = 0; i < cnt; i++)
		{

			if (num >= arr[i]){
				if (num%arr[i] == 0)
					sum += arr[i];
			}
			if (num <= arr[i])
			{
				if (arr[i]%num == 0)
					sum1 += arr[i];

			}
		}

		cout << "#testcase" << (itr + 1) << endl;
		cout << sum << endl;
		cout << sum1 << endl;
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}