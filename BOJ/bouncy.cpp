#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		while (1)
		{
			char num[100];
			cin >> num;
			if (num[0] == '0')
				break;
			int len;
			for (len = 0; num[len] != 0; len++);
			int flag = 0;
			int i;
			for (i = 0; i < len - 1; i++)
			{
				char res = num[i] - num[i + 1];
				if (res>0)
				{
					if (flag == -1)
					{
						cout << "bouncy" << endl;
						break;
					}
					else
						flag = 1;
				}
				else if (res == 0)
				{

				}
				else
				{
					if (flag == 1)
					{
						cout << "bouncy" << endl;
						break;
					}
					flag = -1;
				}
			}
			if (i == len - 1)
				cout << "no bouncy" << endl;

		}

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
