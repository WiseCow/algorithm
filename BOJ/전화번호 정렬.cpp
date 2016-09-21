#include <iostream>
using namespace std;

void sort_last(char(*arr)[14], int max)
{
	for (int i = 0; i < max - 1; i++)
	{
		for (int j = 0; j < max - 1 - i; j++)
		{
			int len1, len2;
			for (; arr[j][len1] != 0; len1++);
			for (; arr[j + 1][len2] != 0; len2++);
			
			int big = 0;
			for (int i = 4; i > 0; i--)
			{
				if (arr[j][len1 - i] > arr[j + 1][len2 - i])
				{
					big = 1;
					break;
				}
				else if (arr[j][len1 - i] == arr[j + 1][len2 - i])
					continue;
				else
				{
					big = -1;
					break;
				}
			}
			if (big != 0)
			{
				if (big == -1)
				{

				}
			}
		}
	}
}

int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		char arr[50][14] = { 0 };
		int num;
		cin >> num;
		int phone[6];
		for (int i = 0; i < 6; i++)
		{
			cin >> phone[i];
		}

		for (int i = 0; i < num; i++)
		{
			cin >> arr[i];
		}

		sort_last(arr,num);






	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}