 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int num;
		cin >> num;
		int arr1[50000];
		int arr2[50000];
		for (int i = 0; i < num; i++)
		{
			cin>>arr1[i];
		}
		int num2;
		cin >> num2;
		for (int i = 0; i < num2; i++)
		{
			cin >> arr2[i];
		}

		
			bool flag = 0;
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num2; j++)
			{
				if (arr1[i] + arr2[j] == 10000)
				{
					flag = 1;
					break;
				}
				if (arr1[i] + arr2[i] < 10000)
					break;
			}
			if (flag == 1)
			{
				break;
			}
		}
		if (flag == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}