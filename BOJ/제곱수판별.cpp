#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int num;
		cin >> num;
		int flag = 0;
		for (int i = 1; i < 1000; i++)
		{
			if (num%i == 0)
				flag++;
		}
		if (flag % 2 == 0)
			cout << "no" << endl;
		else
			cout << "yes" << endl;

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}