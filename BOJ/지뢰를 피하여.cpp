#include<iostream>

using namespace std;


int main()
{
	char map[1000][100] = { 0, };
	int tc;
	cin >> tc;
	int c, r;

	for (int i = 0; i < tc; i++)
	{
		cin >> c >> r;
		for (int j = 0; j < c; j++)
		{
			cin >> map[j];
		}
		for (int j = 0; j < c; j++)
		{
			for (int k = 0; k < r; k++)
			{
				if (map[j][k] == '*')
				{
					for (int n = -1; n < 2; n++)
					{
						for (int m = -1; m < 2; m++)
						{
							if (n == 0 && m == 0)
							{
								continue;
							}
							else
							{
								if (j + n < 0 || k + m < 0 || j + n == c || k + m == r)
									continue;
								else if (map[j + n][k + m] == '*' || map[j + n][k + m] == '#')
									continue;
								else
									map[j + n][k + m] = '1';
							}
						}
					}
				}
				else if (map[j][k] == '#')
				{
					for (int n = -2; n < 3; n++)
					{
						for (int m = -2; m < 3; m++)
						{
							if (n == 0 && m == 0)
							{
								continue;
							}
							else
							{
								if (j + n < 0 || k + m < 0 || j + n == c || k + m == r)
									continue;
								else if (map[j + n][k + m] == '*' || map[j + n][k + m] == '#')
									continue;
								else
									map[j + n][k + m] = '1';
							}
						}
					}

				}
			}
		}
		for (int j = 0; j < c; j++)
		{
			for (int k = 0; k < r; k++)
			{
				if (map[j][k] == '.')
					cout << 0;
				else
					cout << map[j][k];
			}
			cout << endl;
		}
	}


}