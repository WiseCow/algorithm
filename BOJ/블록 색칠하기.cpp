 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int a, b, c;

		cin >> a >> b >> c;

		int r = a + b + c;

		r -= 6;
		r *= 4;

		cout << r << endl;
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}