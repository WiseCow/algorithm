 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		bool sosu[1000000];
		for (int i = 2; i < 1000000; i++)
		{
			for (int j = 2; j < 1000000; j++)
			{
				sosu[i*j] = 1;
			}
		}


		cout << sosu << endl;

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}