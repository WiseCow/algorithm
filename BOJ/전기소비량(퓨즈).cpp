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

		cout << "#testcase" << (itr + 1) << endl;

		double com, prin, rout;
		cin >> com >> prin >> rout;

		com *= 2.5;
		prin *= 2.0;
		rout *= 0.5;
		int sum = (com + prin + rout)*2;
		int flag = 0;
		if (sum % 10 == 0)
			flag = 1;
		sum /= 10;
		if (flag == 0)
			sum = (sum + 1) * 10;
		else
			sum *= 10;
		cout << sum<<" amperes"<<endl;

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}