#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int A, B;
		char cmd[2];
		cin >> A >> B >> cmd;

		switch (cmd[0])
		{
		case '+':
			cout << A + B << endl;
			break;

		case '-':
			cout << A - B << endl;
			break;

		case '*':
			cout << A * B << endl;
			break;

		case '/':
			if (B == 0)
				cout << "-9999" << endl;
			else
				cout << A / B << endl;
			break;
		}

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}