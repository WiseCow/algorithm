 

#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int a, b;
		char add[2];

		cin >> a >> add >> b;
		cout << a << add << b<<"=";
		if (add[0] == '+')
			cout << a + b << endl;
		else if (add[0] == '-')
			cout << a - b << endl;
		else if (add[0] == '/')
			cout << a / b << endl;
		else if (add[0] == '*')
			cout << a * b << endl;

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}