/*

VCPP, GPP���� ���

*/

#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{
		int cnt;
		int type;
		cin >> cnt>>type;
		
		int star = cnt;
		
		

		cout << "#testcase" << (itr + 1) << endl;
		if (type == 2)
		{
			for (int i = 0; i < cnt; i++)
			{
				for (int j = 0; j < star - i; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}

		}
		else if (type == 1)
		{
			for (int i = 0; i < cnt; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
		}
		else
		{
			for (int i = 0; i < cnt; i++)
			{
				for (int j = 0; j < star - i; j++)
				{
					cout << "  ";
				}
				for (int j = 0; j < 2*i+1; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}

		}

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}