/*

VCPP, GPP���� ���

*/

#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{
		int cnt;
		cin >> cnt;
		int arr[100];
		for (int i = 0; i < cnt; i++)
		{
			cin >> arr[i];
		}
		int num;
		cin >> num;
		int sum = 0;
		int sum1 = 0;

		for (int i = 0; i < cnt; i++)
		{

			if (num >= arr[i]){
				if (num%arr[i] == 0)
					sum += arr[i];
			}
			if (num <= arr[i])
			{
				if (arr[i]%num == 0)
					sum1 += arr[i];

			}
		}

		cout << "#testcase" << (itr + 1) << endl;
		cout << sum << endl;
		cout << sum1 << endl;
		/*

		�˰����� ���� �κ�

		*/

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}