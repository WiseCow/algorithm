#include <iostream>
using namespace std;
int main()
{

	int nCount;

	cin >> nCount;
	for (int itr = 0; itr<nCount; itr++)
	{
		int cnt;
		cin >> cnt;
		char arr[100];
		cin >> arr;

		cout << "#testcase" << (itr + 1) << endl;

		for (;;)
		{

			int a = 0;

			for (int i = 0; i < cnt; i++)
			for (int j = i; j < cnt; j++)
			{
				if (i == j || arr[i] == '*')
					continue;
				if (arr[i] == arr[j] && j - i == 1)
				{
					arr[i] = '*';
					arr[j] = '*';
					a++;

				}
				else
				{
					if (arr[j] == '*')
						continue;
					else if (arr[i] == arr[j])
					{
						int flag = 0;
						for (int k = 0; k < j - i; k++)
						if (arr[i + k] == '*')
						{
							flag++;
						}
						if (flag == j - i - 1)
						{
							arr[i] = '*';
							arr[j] = '*';
							a++;

						}
					}
				}
			}

			if (a == 0)
				break;



		}
		for (int i = 0; i < cnt; i++)
		{
			if (arr[i] != '*')
				cout << arr[i];
		}
		cout << endl;
	}

	return 0;

}
