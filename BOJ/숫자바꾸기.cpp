 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int a, b, c;
		cin >> a >> b;

		c = a ^ b;


		int j = 4194304;
		int flag = 0;


		for (int i = 0; j>0; i++)
		{
			if (c / j)
			{
				int tmp = c/j;
				c -= tmp*j;
				flag++;
			}
			j /= 2;
		}
		cout << flag << endl;


	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}