 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int arr[10001] = { 0 };

		for (int i = 2; i < 10000; i++)
		{
			for (int j = 2;i*j <= 10000; j++)
			{
				arr[i*j] = 1;
			}
		}
		int a, b;
		cin >> a >> b;

		int flag = 0;
		for (int i = a ; i < b + 1; i++)
		{
			if (arr[i] == 0)
				flag++;
		}

		cout << flag << endl;
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}