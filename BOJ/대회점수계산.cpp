#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int cnt, res = 0, max = 0, min = 10000;
		cin >> cnt;
		for (int i = 0; i < cnt; i++)
		{
			int tmp;
			cin >> tmp;
			res += tmp;
			if (min>tmp)
				min = tmp;
			if (max < tmp)
			{
				max = tmp;
			}
		}
		res = res - min - max;
		cout << res / (cnt - 2) << endl;
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}