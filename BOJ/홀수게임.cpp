
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		long long int num;
		cin >> num;
		long long int arr[10000] = { 0, };

		if (num == 1)
		{
			cout << 1 << endl;
		}
		else
		{
			num = (num - 1) / 2;
			arr[0] = 1;
			arr[1] = 5;
			for (int i = 2; i <= num; i++)
			{
				arr[i] = arr[i - 1] + (i * 2 + 1)*2;
			}
			cout << arr[num]*3 << endl;
		}



	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}