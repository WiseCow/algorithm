 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int member;
		cin >> member;
		int people[80000];
		for (int i = 0; i < member; i++)
		{
			cin >> people[i];
		}
		int flag=0;
		for (int i = 0; i < member; i++)
		{
			for (int j = i + 1; j < member; j++)
			{
				if (people[i]>people[j])
				{
					flag++;
				}
				else
					break;
			}
		}
		cout << flag << endl;


	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}