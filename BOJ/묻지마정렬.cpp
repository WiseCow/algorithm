#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int p[4] = { 0 };
		int arr[4][70] = { 0 };

		int cnt;
		cin >> cnt;
		for (int i = 0; i < cnt; i++)
		{
			int ban,num;
			cin >> ban>>num;
			arr[ban - 1][p[ban - 1]++] = num;
		}
		for (int i = 0; i <= p[0]-1; i++)
		{
			for (int j = 0; j < p[0] - i - 1; j++)
			{
				if (arr[0][j] > arr[0][j + 1])
				{
					int tmp = arr[0][j];
					arr[0][j] = arr[0][j + 1];
					arr[0][j + 1] = tmp;
				}
			}
		}
		for (int i = 0; i < p[0]; i++)
			cout << "1 " << arr[0][i] << endl;

		for (int i = 0; i <= p[3] - 1; i++)
		{
			for (int j = 0; j < p[3] - i - 1; j++)
			{
				if (arr[3][j] > arr[3][j + 1])
				{
					int tmp = arr[3][j];
					arr[3][j] = arr[3][j + 1];
					arr[3][j + 1] = tmp;
				}
			}
		}
		for (int i = p[3]-1; i>=0; i--)
			cout << "4 " << arr[3][i] << endl;
		for (int i = 0; i <= p[1] - 1; i++)
		{
			for (int j = 0; j < p[1] - i - 1; j++)
			{
				if (arr[1][j] > arr[1][j + 1])
				{
					int tmp = arr[1][j];
					arr[1][j] = arr[1][j + 1];
					arr[1][j + 1] = tmp;
				}
			}
		}
		for (int i = p[1] - 1; i >= 0; i--)
			cout << "2 " << arr[1][i] << endl;

		for (int i = 0; i <= p[2] - 1; i++)
		{
			for (int j = 0; j < p[2] - i - 1; j++)
			{
				if (arr[2][j] > arr[2][j + 1])
				{
					int tmp = arr[2][j];
					arr[2][j] = arr[2][j + 1];
					arr[2][j + 1] = tmp;
				}
			}
		}
		for (int i = 0; i < p[2]; i++)
			cout << "3 " << arr[2][i] << endl;



	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}