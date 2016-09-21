
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int arr[3] = { 1, 3, 4 };
		int res[100000] = { 0 };

		int num;
		cin >> num;


		res[0] = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = arr[i]; j <= num; j ++)
			{
					res[j] = res[j - arr[i]] + res[j];
			}
		}
		cout << res[0] << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}