 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{
		char foo[300];
		cin >> foo;

		int a = strlen(foo);

		for (int i = 0; i < a - 2; i++)
		{
			if (foo[i] == 'F' && foo[i+1] == 'O' &&foo[i+2] == 'O')
			{
				foo[i] = 'O';
				foo[i+1] = 'O';
				foo[i+2] = 'F';

			}
		}
		cout << "#testcase" << (itr + 1) << endl;
		cout << foo<<endl;
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}