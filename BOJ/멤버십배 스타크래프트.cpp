#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int cnt;
		cin >> cnt;

		int sang[1000] = { 0 };
		int gj[1000] = { 0 };

		for (int i = 0; i < cnt; i++)
		{
			cin >> sang[i];
		}
		for (int i = 0; i < cnt; i++)
		{
			cin >> gj[i];
		}
		for (int i = 0; i < cnt; i++)
		{
			int max = i;
			for (int j = i + 1; j < cnt; j++)
			{
				if (sang[max] < sang[j])
					max = j;
			}
			if (max != i)
			{
				int tmp = sang[i];
				sang[i] = sang[max];
				sang[max] = tmp;
			}
		}
		for (int i = 0; i < cnt; i++)
		{
			int max = i;
			for (int j = i + 1; j < cnt; j++)
			{
				if (gj[max] < gj[j])
					max = j;
			}
			if (max != i)
			{
				int tmp = gj[i];
				gj[i] = gj[max];
				gj[max] = tmp;
			}
		}
		int sp = 0, gp = 0;


		int sum = 0;

		while (sp != cnt)
		{
			if (sang[sp] > gj[gp])
			{
				sp++;
			}
			else
			{
				sp++;
				gp++;
				sum++;
			}
		}
		cout << sum << endl;


	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}


