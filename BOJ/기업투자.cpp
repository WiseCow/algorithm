#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int x, y;
		cin >> x >> y;
		int arr[400][20] = { 0 };
		int res[400][20] = { 0 };
		for (int i = 1; i <= x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i <= x; i++)
		{
			int max = 0;
			for (int k = 0; k <= i; k++)
			{
				if (arr[i - k][0] + arr[k][1]>max)
					max = arr[i - k][0] + arr[k][1];
			}
			res[i][0] = max;
		}
		for (int l = 2; l < y; l++)
		{

			for (int i = 0; i <= x; i++)
			{
				int max = 0;
				for (int k = 0; k <= i; k++)
				{
					if (res[i - k][l - 2] + arr[k][l]>max)
						max = res[i - k][l - 2] + arr[k][l];
				}
				res[i][l - 1] = max;
			}
		}
		cout << res[x][y - 2] << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
