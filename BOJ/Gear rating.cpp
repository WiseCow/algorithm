/*

VCPP, GPP���� ���

*/

#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr < nCount; itr++)
	{
		int f_d, r_d;
		float f_t[100], r_t[100];
		cin >> f_d >> r_d;
		for (int i = 0; i < f_d; i++)
		{
			cin >> f_t[i];

		}
		for (int i = 0; i < r_d; i++)
		{
			cin >> r_t[i];

		}
		float result[10000];
		int res = 0;
		for (int i = 0; i < f_d; i++)
		for (int j = -0; j < r_d; j++)
		{
			result[res] = r_t[j] / f_t[i];
			res++;
		}

		for (int i = 0; i < res - 1; i++){
			for (int j = 0; j < res - i - 1; j++)
			if (result[j]>result[j + 1])
			{
				float tmp = result[j];
				result[j] = result[j + 1];
				result[j + 1] = tmp;
			}
		}


		cout << "#testcase" << (itr + 1) << endl;
		float _max = -1000.0;
		for (int i = 0; i < res - 1; i++)
		{
			if (result[i + 1] / result[i]>_max)
				_max = result[i + 1] / result[i];
		}
		printf("%.2f\n", _max);
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}