 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{
		
		int arr[100];
		int _max=0, flag;

		for (int i = 0; i < 4; i++)
		{
			cin >> arr[i];
			if (arr[i]>_max)flag = i, _max = arr[i];
		}
		cout << "#testcase" << (itr + 1) << endl;

		cout << arr[flag] << "\n" << flag + 1 << endl;

		/*

		�˰����� ���� �κ�

		*/

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}