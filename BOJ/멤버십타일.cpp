#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{
		int x, y;
		cin >> x >> y;
		int x_f, y_f;
		int x_d, y_d;

		cout << "#testcase" << (itr + 1) << endl;
		x_d = x / 6;
		y_d = y / 6;
		x_f = (x % 6)>0?1:0;
		y_f = (y % 6)>0?1:0;

		int m;
		if (x_f == 1 && y_f == 1){
			m = x_d + y_d + 1;
		}
		else if (x_f == 1)
		{
			m = y_d;
		}
		else if (y_f == 1)
		{
			m = x_d;
		}
		else
			m = 0;
				cout << x_d*y_d << " "<<m<<endl;



	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}