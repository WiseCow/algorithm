/*

VCPP, GPP���� ���

*/

#include <iostream>
using namespace std;
int main()
{

	bool arr[100000] = { 0, };

	for (int i = 2; i < 100000; i++)
	{
		for (int j = 2; j*i < 100000; j++)
			arr[j*i] =1;
	}



	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int num;
		cin >> num;
		if (arr[num] == 1)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;


		 

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}