/*

VCPP, GPP에서 사용

*/

#include <iostream>
#include<string.h>

using namespace std;
int main()
{
	int arr[10001] = { 0, };
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= 10000; i++)
	{
		for (int j = 2; j*i < 10000; j++)
		{
			arr[i*j] = 1;
		}
	}
	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int chk = 0;
		char ch[10000];
		cin >> ch;
		int a = strlen(ch);

		for (char i = 'A'; i <= 'Z'; i++)
		{
			int flag = 0;
			for (int j = 0; j < a; j++)
			{
				if (ch[j] == i)
					flag++;

			}
			if (arr[flag] == 0)
			{
				cout << i;
				chk++;

			}
		}
		if (chk == 0)
			cout<<"NONE" << endl;
		else
			cout << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}