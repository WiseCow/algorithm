#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		int brain[100];
		int magic;
		int input;
		int son;
		int sum = 0;
		cin >>son;
		cin>> magic;
		for (int i = 0; i < son; i++)
		{
			cin >> input;
			brain[i] = input;
			for (int j = 0; j < magic-1; j++)
				brain[i] *= input;
		}

		for (int i = 0; i < son; i++)
		{
			if (brain[i]>0)
				sum += brain[i];

		}



		cout << "#testcase" << (itr + 1) << endl;
		cout << sum<<endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}