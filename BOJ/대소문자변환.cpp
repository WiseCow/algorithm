 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		char arr[1000];
		cin >> arr;

		for (int i = 0; arr[i] != 0; i++)
		{
			if (arr[i] < 91)
				printf("%c", (arr[i] + 32));
			else
				printf("%c", (arr[i] - 32));
		}
		cout << endl;

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}