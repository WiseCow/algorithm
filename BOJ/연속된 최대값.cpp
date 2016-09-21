#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int cnt;
		int num;

		cin >> num >> cnt;
		int arr[100];
		for (int i = 0; i < num;i++)
		cin >> arr[i];
		int _max = 0;


		for (int i = 0; i <= num-cnt; i++)
		{
			int sum = 0;

			for (int j = 0; j < cnt; j++)
			{
				sum += arr[i + j];
			}
			if (sum>_max)
				_max = sum;
		}
		cout << _max << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}