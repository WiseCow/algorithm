
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		char arr[100];
		int cnt = 0;
		cin >> arr;
		while (1)
		{
			if (arr[cnt] == 0)
			{
				break;
			}
			cnt++;
		}

		for (int i = 0; i < cnt; i++)
		{
			if (arr[i] == 'W')
			{
				arr[i] = 'S';
			}
			else if (arr[i] == 'E')
			{
				arr[i] = 'O';
			}
			else if (arr[i] == 'G')
			{
				arr[i] = 'F';
			}
			else if (arr[i] == 'V')
			{
				arr[i] = 'T';
			}
			else if (arr[i] == 'M')
			{
				arr[i] = 'W';
			}
			else if (arr[i] == 'L')
			{
				arr[i] = 'A';
			}
			else if (arr[i] == 'Q')
			{
				arr[i] = 'R';
			}
			else if (arr[i] == 'A')
			{
				arr[i] = 'E';
			}
			else if (arr[i] == 'L')
			{
				arr[i] = 'A';
			}
			else if (arr[i] == 'B')
			{
				arr[i] = 'B';
			}
			else if (arr[i] == 'A')
			{
				arr[i] = 'D';
			}
			else if (arr[i] == 'S')
			{
				arr[i] = 'M';
			}
			else if (arr[i] == 'F')
			{
				arr[i] = 'G';
			}





		}
		cout << arr << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}