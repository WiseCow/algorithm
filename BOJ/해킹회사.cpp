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
		int r, e, c;
		cin >> r >> e >> c;

		cout << "#testcase" << (itr + 1) << endl;

		if (r>e - c)
			cout << "do not advertise" << endl;
		else if (r == (e - c))
			cout << "does not matter" << endl;
		else
			cout << "advertise" << endl;

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}