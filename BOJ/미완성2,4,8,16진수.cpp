#include <iostream>
#include<string.h>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0;itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		char arr[10];
		cin >> arr;
		int res = 0;
		int size = strlen(arr);

		if (arr[0] =='B')
		{
			for (int i = size-1 , j=1; i > 0; i-=2 , j*=2)
			{
				res +=(arr[i]-48) * j;
			}
		}
		else if (arr[0] == 'Q')
		{
			for (int i = size - 1, j = 1; i > 0; i -= 2, j *= 4)
			{
				res += (arr[i] - 48) * j;
			}
		}
		else if (arr[0] == 'O')
		{
			for (int i = size - 1, j = 1; i > 0; i -= 2, j *= 8)
			{
				res += (arr[i] - 48) * j;
			}
		}
		else if (arr[0] == 'H')
		{
			for (int i = size - 1, j = 1; i > 0; i -= 2, j *= 16)
			{
				if (arr[i] - 48 > 10)
				{
					if (arr[i] == 'A')
						res += 10 * j;
					else if (arr[i] == 'B')
						res += 11 * j;
					else if (arr[i] == 'C')
						res += 12 * j;
					else if (arr[i] == 'D')
						res += 13 * j;
					else if (arr[i] == 'E')
						res += 14 * j;
					else if (arr[i] == 'F')
						res += 15 * j;
				}
				else
				{
					res += (arr[i] - 48) * j;
				}
			}
		}
		if (res == 0)break;
		cout << res << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}