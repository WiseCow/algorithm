/*

VCPP, GPP���� ���

*/

#include <iostream>
using namespace std;
int main()
{

	int nCount=1;		/* ������ �׽�Ʈ ���̽� */

	//cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{
		
		cout << "#testcase" << (itr + 1) << endl;
		for (int i = 100; i < 1000; i++)
		{
			int a=i,x, y, z;
			x = a / 100;
			a -= x * 100;
			y = a / 10;
			a -= y * 10;
			z = a;
			if (x*x*x + y*y*y + z*z*z == i)
				cout << i << endl;
		}
		/*

		�˰����� ���� �κ�

		*/

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}