

#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{
		int gugu;
		cin >> gugu;

		cout << "#testcase" << (itr + 1) << endl;

		for (int i = 1; i < 10; i++)
			cout << gugu << "*" << i << "=" << gugu*i << endl;
		/*

		�˰����� ���� �κ�

		*/

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}