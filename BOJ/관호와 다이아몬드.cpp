#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int a;
		cin >> a;
		for (int i = 0; i < a; i++)
		{
			for (int k = a - i; k >1; k--)
			{
				printf(" ");
			}
			for (int k = 0; k < i * 2 + 1; k++)
			{
				cout << "*";
			}
			cout << endl;
		}
		for (int i = a-2; i>=0; i--)
		{
			for (int k = a - i; k >1; k--)
			{
				printf(" ");
			}
			for (int k = 0; k < i * 2 + 1; k++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}