
#include <iostream>
using namespace std;
int fibo(int a)
{
	if (a == 1)
		return 1;
	else if (a == 2)
		return 1;
	else
	{
		return fibo(a - 1) + fibo(a - 2);
	}
}


int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int D, K;
		cin >> D >> K;

		int a = fibo(D - 2);
		int b = fibo(D - 1);

		int flag = 0;

		int i, j;
		for (i = 1;; i++)
		{
			for (j = 1;; j++)
			{
				if (a*i + b*j > K)
					break;
				else if (a*i + b*j == K)
				{
					flag = 1;
					break;

				}
			}
			if (flag == 1)
				break;
		}

		cout << i << endl << j << endl;

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}