 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		char arr[50];
		cin >> arr;
		int cnt = 0;
		for (; arr[cnt] != 0; cnt++);

		int sum = 10;

		for (int i = 1; i < cnt; i++)
		{
			if (arr[i - 1] == arr[i])
				sum += 5;
			else
			sum += 10;
		}
		cout << sum<<endl;
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}