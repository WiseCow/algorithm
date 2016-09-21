#include <iostream>
using namespace std;
int main()
{

	int ncount;		/* 문제의 테스트 케이스 */

	cin >> ncount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < ncount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		char arr[100] = { 0 };
		cin >> arr;
		int n, k;
		cin >> n >> k;
		int flag = 0;
		int res = 0;
		if (arr[0] == '-')
			flag = 1;
		int cnt;
		for (cnt = 0; arr[cnt] != 0; cnt++);
		long long sum = 0;
		long long dup = 1;
		if (n < 10)
			for (int i = cnt - 1; i >= flag; i--)
			{
				sum += (arr[i] - 48) * dup;
				dup *= n;

			}
		else
		{
			for (int i = cnt - 1; i >= flag; i--)
			{
				if (arr[i] >= 'A')
				{
					sum += (arr[i] - 55)*dup;
				}
				else
					sum += (arr[i] - 48) * dup;
				dup *= n;

			}
		}
		char result[100] = { 0 };
		if (sum == 0)
			cout << "0" << endl;
		if (k < 10)
		{
			int i;
			for (i = 0; sum != 0; i++)
			{
				int a = sum % k;
				result[i] = a+48;
				sum /=k;
			}
			if (flag == 1)
				result[i++] = '-';
			for (i -= 1; i >= 0; i--)
			{
				printf("%c", result[i]);
			}
			cout << endl;
		}
		else if (k == 10)
		{
			if (flag == 1)
			{
				printf("-");
			}
			cout << sum << endl;;
		}
		else
		{
			int i;
			for (i = 0; sum != 0; i++)
			{
				int a = sum % k;
				if (a > 9)
				{
					result[i] = a + 55;
				}
				else
				{
					result[i] = a + 48;
				}
				sum /= k;
			}
			if (flag == 1)
				result[i++] = '-';
			for (i -= 1; i >= 0; i--)
			{
				printf("%c", result[i]);
			}
			cout << endl;
		}		
	}
		return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}