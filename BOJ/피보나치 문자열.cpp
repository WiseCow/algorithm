#include <iostream>
using namespace std;
void _strcat(char *a, char *b, char *c)
{
	int i = 0;
	for (; b[i] != 0; i++)
	{
		c[i] = b[i];
	}
	int j = 0;
	for (; a[j] != 0; j++)
	{
		c[i + j] = a[j];
	}
	b[i + j] = 0;
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int cnt;
		cin >> cnt;
		char arr1[11] = { 0 };
		char arr2[11] = { 0 };
		cin >> arr1 >> arr2;
		char res[100][1000] = { 0 };
		res[0][0] = '1';
		res[1][0] = '2';
		if (cnt > 1)
			cout << arr1 << endl;
		if (cnt > 2)
			cout << arr2 << endl;
		for (int i = 2; i < cnt; i++)
		{
			_strcat(res[i - 2], res[i - 1], res[i]);
			int k = 0;
			for (; res[i][k] != 0; k++);

			for (k = k - 1; k >= 0; k--)
			{
				if (res[i][k] == '2')
					cout << arr2;
				else
					cout << arr1;
			}
			cout << endl;
		}


	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}