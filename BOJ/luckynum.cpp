 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int num;
		cin >> num;
		int arr[10000] = { 0 };
		int point = 0;
		while (num!=0)
		{
			if (num % 2 == 0)
			{
				arr[point++] = 7;
				num -= 2;
			}
			else
			{
				arr[point++] = 4;
				num -= 1;
			}
			num /= 2;
		}

		for (int i = point-1; i >=0; i--)
			cout << arr[i];
		cout << endl;
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}