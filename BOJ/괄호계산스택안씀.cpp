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
		cin >> arr;
		char stack[100] = { 0 };
		int st_p = 0, stn_p = 0;
		int stack_num[100] = { 0 };

		int flag = 0;
		for (int i = 0; arr[i] != 0; i++)
		{
			if (arr[i] == '(' || arr[i] == '[')
			{
				stack[st_p++] = arr[i];
			}
			else
			{
				if (stack[st_p - 1] == '('&&arr[i] == ')')
				{
					st_p--;
					if (stack_num[st_p + 1] == 0)
						stack_num[st_p] += 2;
					else
					{
						stack_num[st_p] += stack_num[st_p + 1] * 2;
						stack_num[st_p+1] = 0;
					}
				}
				else if (stack[st_p - 1] == '['&&arr[i] == ']')
				{
					st_p--;
					if (stack_num[st_p + 1] == 0)
						stack_num[st_p] += 3;
					else
					{
						stack_num[st_p] += stack_num[st_p + 1] * 3;
						stack_num[st_p+1] = 0;
					}
				}
				else
				{
					flag = 1;
					break;
				}
			}
		}


		if (flag == 1)
			cout << 0 << endl;
		else
		{
			cout << stack_num[0] << endl;
		}




	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}