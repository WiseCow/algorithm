#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		long long ques = 1, mod = 10;
		long a;
		int arr[11] = { 0, };
		for (int i = 0; i < 3; i++)
		{
			cin >> a;
			ques *= a;
		}
		bool flag = 0;

		for (int i = 0;; i++)
		{
			int num = ques%mod;
				ques /= 10;
				arr[num]++;
				if (ques == 0)
					break;
		}



		for (int i = 0; i < 10; i++)
		{
			cout << arr[i] << endl;
		}



	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}