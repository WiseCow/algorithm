#include <iostream>
#include<string.h>
#include<math.h>

using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int cnt;
		cin >> cnt;
		int min = 1000;
		int max = 0;
		for (int i = 0; i < cnt; i++)
		{
			int a = 0;
			cin >> a;
			if (a>max)
				max = a;
			if (a < min)
				min = a;
		}
		cout << max - min << endl;
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}