#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int c;
		cin >> c;
		int sum = 0;
		int sumsum = 0;
		for (int i = 1; i <= c; i++)
			sum += i, sumsum+=sum;
		cout << sumsum << endl;

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}