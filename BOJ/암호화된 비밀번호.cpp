#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{
		cout << "#testcase" << (itr + 1) << endl;
		char arr[101];
		int len;
		cin >> arr;
		for (int i = 0;; i++)
		{
			if (arr[i] == 0){
				len = i;
				break;
			}
		}		
		if (arr[0] == 'R')
		{
			int num = arr[1] - 48;


			for (int i = len - num; i < len; i++)
				printf("%c", arr[i]);
			for (int i = 2; i < len - num;i++)
				printf("%c", arr[i]);
			cout << endl; 
		}
		else
		{
			int num = arr[1] - 48;
			for (int i = 2+num; i < len; i++)
				printf("%c", arr[i]);
			for (int i = 2; i <2+num; i++)
				printf("%c", arr[i]);
			cout << endl;
		}
	}
	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */
}
