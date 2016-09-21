#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int map[101][101] = { 0 };

		int cnt;
		cin >> cnt;

		for (int i = 0; i < cnt; i++)
		{
			int x, y;
			cin >> x >> y;

			for (int k = 0; k < 10; k++)
			{
				for (int l = 0; l < 10; l++)
				{
					if (x + k < 100 && y + l < 100)
						map[x + k][y + l] = 1;
				}
			}
		}

		int sum = 0;
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				if (map[i][j] == 0 && map[i][j+1] == 1)
					sum++;
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++
				)
				if (map[i][j] == 1 && map[i][j+1] == 0)
					sum++;
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				if (map[i][j] == 0 && map[i+1][j] == 1)
					sum++;
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				if (map[i][j] == 1 && map[i+1][j] == 0)
					sum++;


		cout << sum << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}