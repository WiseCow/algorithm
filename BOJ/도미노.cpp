 

#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int i;
		cin >> i;
		int res = 3;
		for (int k = 1; k < i; k++)
		{
			res = res + 2+k;
		}

		cout << res << endl;
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}