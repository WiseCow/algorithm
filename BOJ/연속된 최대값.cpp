#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int cnt;
		int num;

		cin >> num >> cnt;
		int arr[100];
		for (int i = 0; i < num;i++)
		cin >> arr[i];
		int _max = 0;


		for (int i = 0; i <= num-cnt; i++)
		{
			int sum = 0;

			for (int j = 0; j < cnt; j++)
			{
				sum += arr[i + j];
			}
			if (sum>_max)
				_max = sum;
		}
		cout << _max << endl;

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}