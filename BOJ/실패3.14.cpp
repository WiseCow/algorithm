
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int arr[3] = { 1, 3, 4 };
		int res[100000] = { 0 };

		int num;
		cin >> num;


		res[0] = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = arr[i]; j <= num; j ++)
			{
					res[j] = res[j - arr[i]] + res[j];
			}
		}
		cout << res[0] << endl;
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}