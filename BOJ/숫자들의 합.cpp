 
#include <iostream>
using namespace std;

int res[1000001];
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int num;
		cin >> num;
		int arr[10000];
		arr[0] = 1;
		int cnt;
		for (cnt = 1; arr[cnt-1]<num; cnt++)
		{ 
			arr[cnt] = arr[cnt - 1] * 2;
			
		}
		cnt--;
		for (int i = 0; i <= num; i++)
		{
			res[i] = arr[0];
		}
		for (int k = 1; k < cnt; k++)
		{
			for (int i = 0; i <= num - arr[k]; i++)
			{
				res[i + arr[k]] = (res[i] + res[i + arr[k]])%1000000000;
			}
		}
		cout << res[num]<<endl;

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}