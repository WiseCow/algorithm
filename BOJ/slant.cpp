 

#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int x1, y1, x2, y2;
		cin>> x1 >> y1;
		cin>> x2 >> y2;

		if (x1 < x2)
		{
			x1 = x2 - x1;
			y1 = y2 - y1;
		}
		else
		{
			x1 = x1 - x2;
			y1 = y1 - y2;
		}
		int i;
		for ( i = 0; x1*i < y1; i++);
		cout << i << " "<< y2-x2*i<< endl;

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}