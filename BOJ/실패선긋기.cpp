#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int in;
		cin >> in;


		int arr[20];

		arr[0] = 1;
		int tmp = 1;
		for (int i = 1; i < in; i++,tmp*=3)
		{
			arr[i] = arr[i - 1] + tmp;
		}
		cout << arr[in - 1] << endl;

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}