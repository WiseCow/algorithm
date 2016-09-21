#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int a, b, c;
		cin >> a >> b >> c;
		int x, y;
		bool flag = 0;
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j <b; j++)
			if ((c-1) == b*i + j)
			{
				flag = 1;
				x = i;
				y = j;
				break;
			}
			if (flag == 1)
			{
				break;
			}
		}
		int arr[100][100];
		arr[0][0] = 1;
		for (int i = 0; i <= x; i++)
		{
			for (int j = 0; j <= y; j++)
			{
				if (i == 0 || j == 0)
					arr[i][j] = 1;
				else
					arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
		}
		int mid;
		if (c != 0)
			mid = arr[x][y];
		else{
			mid = 1;
			x = 0, y = 0;
		}
		arr[x][y] = 1;
		for (int i = x; i < a; i++)
		{
			for (int j = y; j < b; j++)
			{
				if (i == x || j == y)
					arr[i][j] = 1;
				else
					arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
		}
		int end = arr[a-1][b-1];


		cout << mid*end << endl;




	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}