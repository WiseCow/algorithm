#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		long long ques = 1, mod = 10;
		long a;
		int arr[11] = { 0, };
		for (int i = 0; i < 3; i++)
		{
			cin >> a;
			ques *= a;
		}
		bool flag = 0;

		for (int i = 0;; i++)
		{
			int num = ques%mod;
				ques /= 10;
				arr[num]++;
				if (ques == 0)
					break;
		}



		for (int i = 0; i < 10; i++)
		{
			cout << arr[i] << endl;
		}



	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}