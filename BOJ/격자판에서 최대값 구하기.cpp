#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;


		int max = 0;
		int x, y;

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				int num;
				cin >> num;
				if (num>max)
				{
					x = i; y = j;
					max = num;
				}

			}

		}

		cout << max << endl;
		cout << x+1 <<" "<< y+1 << endl;

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}