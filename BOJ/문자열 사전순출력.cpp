//문자열 사전순 출력
#include <iostream>
#include<string.h>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		int count;
		cin >> count;
		char arr[10][100];

		for (int i = 0; i < count; i++)
			cin >> arr[i];

		for (int i = 0; i < count-1; i++)
			for (int j = 0; j < count - i - 1;j++)
				if (strcmp(arr[j], arr[j + 1]) > 0)
				{
					char tmp[100];
					strcpy_s(tmp, arr[j]);
					strcpy_s(arr[j], arr[j+1]);
					strcpy_s(arr[j+1], tmp);

				}


		cout << "#testcase" << (itr + 1) << endl;
		for (int i = 0; i < count; i++)
			cout << arr[i] << endl;

		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
