#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		char arr[100];
		cin >> arr;
		int len;
		for (len = 0;; len++)
		{
			if (arr[len] == 0)
				break;

		}
		int flag=0;

		for (int i = 0; i < len-1; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (arr[i] == arr[j])
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;



	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}