 

#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		char arr[100];
		cin >> arr;
		int sum=0;

		for (int i = 0;; i++)
		{
			if (arr[i] == '0')
				sum += 6;
			else if (arr[i] == '1')
				sum += 2;
			else if (arr[i] == '2')
				sum += 5;
			else if (arr[i] == '3')
				sum += 5;
			else if (arr[i] == '4')
				sum += 4;
			else if (arr[i] == '5')
				sum += 5;
			else if (arr[i] == '6')
				sum += 6;
			else if (arr[i] == '7')
				sum += 3;
			else if (arr[i] == '8')
				sum += 7;
			else if (arr[i] == '9')
				sum += 6;
			else if (arr[i] == 0)
				break;
		}
		cout << sum << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}