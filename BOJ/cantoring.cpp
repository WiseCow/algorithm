#include <iostream>
using namespace std;
int arr[500][500];

int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int max;
		cin >> max;
		char arr[600000] = { 0 };
		int num = 1;
		for (int i = 0; i < max; i++)
		{
			num *= 3;
		}
		for (int i = 0; i < num; i++)
		{
			arr[i] = '-';
		}
		while (num != 1)
		{

			num /= 3;
			int i = 0;
			while (arr[i] != 0)
			{
				while (arr[i] != '-')
				{
					i++;
					if (arr[i] == 0)
						break;
				}
				i += num;
				if (arr[i] == 0)
					break;
				for (int k = 0; k < num; k++)
				{
					arr[i + k] = ' ';
				}
			}
		}
		cout << arr << endl; 
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}