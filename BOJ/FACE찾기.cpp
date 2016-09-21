#include <iostream>
using namespace std;
int main()
{

	int nCount;

	cin >> nCount;

	for (int itr = 0; itr<nCount; itr++)
	{
		int x, y;
		cin >> x >> y;
		char face[100][100];
		for (int i = 0; i < x; i++)
			cin >> face[i];
		int flag = 0;




		cout << "#testcase" << (itr + 1) << endl;
		for (int i = 0; i < x - 1; i++)
		for (int j = 0; j < y - 1; j++)
		{
			int a = 0, b = 0, c = 0, d = 0;
			char ans[4][2];
			ans[0][0] = face[i][j];
			ans[1][0] = face[i][j + 1];
			ans[2][0] = face[i + 1][j];
			ans[3][0] = face[i + 1][j + 1];
			for (int k = 0; k < 4; k++)
			{
				if (ans[k][0] == 'f')
					a++;
				if (ans[k][0] == 'a')
					b++;
				if (ans[k][0] == 'c')
					c++;
				if (ans[k][0] == 'e')
					d++;

			}
			if (a == 1 && b == 1 && c == 1 && d == 1)
			{
				flag++;
			}

		}
		cout << flag << endl;

	}

	return 0;

}