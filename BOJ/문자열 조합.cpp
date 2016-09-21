 

#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		char arr[100000] = { 0, };
		int  ans[27] = { 0, };
		cin >> arr;
		int cnt = 0;
		for (int i = 0; arr[i] != 0; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (arr[i] - 97 - j == 0)
				{

					ans[j]++;
					break;
				}
			}
		}
		for (int i = 0; i < 27; i++)
		{
			if (ans[i]>0)
				cnt++;
		}
		int sum = 0;
		for (int i = 0; i < 27; i++)
		{
			sum += ans[i];
		}

		for (int i = 0; i < 26; i++)
		{
			for (int j = i + 1; j < 27; j++)
				sum += ans[i] * ans[j];
		}
		if (cnt>2)
		{
			sum += ans[0] * ans[1] * ans[2];
		cout << sum << endl;
	}
		else
		cout << sum << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}