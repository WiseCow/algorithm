
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		long long int num;
		cin >> num;
		long long int arr[10000] = { 0, };

		if (num == 1)
		{
			cout << 1 << endl;
		}
		else
		{
			num = (num - 1) / 2;
			arr[0] = 1;
			arr[1] = 5;
			for (int i = 2; i <= num; i++)
			{
				arr[i] = arr[i - 1] + (i * 2 + 1)*2;
			}
			cout << arr[num]*3 << endl;
		}



	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}