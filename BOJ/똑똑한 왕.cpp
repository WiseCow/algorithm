#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{
		int brain[100];
		int magic;
		int input;
		int son;
		int sum = 0;
		cin >>son;
		cin>> magic;
		for (int i = 0; i < son; i++)
		{
			cin >> input;
			brain[i] = input;
			for (int j = 0; j < magic-1; j++)
				brain[i] *= input;
		}

		for (int i = 0; i < son; i++)
		{
			if (brain[i]>0)
				sum += brain[i];

		}



		cout << "#testcase" << (itr + 1) << endl;
		cout << sum<<endl;

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}