 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int cnt, find;
		cin >> cnt >> find;
		char arr[101] = { 1, };

		for (int i = 2; i <= cnt; i++)
		{
			for (int j = 1;; j++)
			{
				if (i*j > 100)
					break;
				if (arr[i*j] == 0)
					arr[i*j] = 1;
				else
					arr[i*j] = 0;
			}
		}

		if (arr[find] == 0)
			cout << 1 << endl;
		else
			cout << 0 << endl; 

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}