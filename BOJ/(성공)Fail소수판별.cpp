/*

VCPP, GPP에서 사용

*/

#include <iostream>
using namespace std;
int main()
{

	bool arr[100000] = { 0, };

	for (int i = 2; i < 100000; i++)
	{
		for (int j = 2; j*i < 100000; j++)
			arr[j*i] =1;
	}



	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int num;
		cin >> num;
		if (arr[num] == 1)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;


		 

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}