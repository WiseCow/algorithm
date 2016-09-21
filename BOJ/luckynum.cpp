 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int num;
		cin >> num;
		int arr[10000] = { 0 };
		int point = 0;
		while (num!=0)
		{
			if (num % 2 == 0)
			{
				arr[point++] = 7;
				num -= 2;
			}
			else
			{
				arr[point++] = 4;
				num -= 1;
			}
			num /= 2;
		}

		for (int i = point-1; i >=0; i--)
			cout << arr[i];
		cout << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}