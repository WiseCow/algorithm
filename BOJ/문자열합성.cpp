#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr < nCount; itr++)
	{
		char word[2][105];
		int cnt;
		cin >> word[0];
 		cin >> word[1] >> cnt;


		cout << "#testcase" << (itr + 1) << endl;
		cout << word[0];
		cout << word[1] << endl;
		for (int i = 0; i < cnt; i++)
		{
			word[1][i] = word[0][i];
		}
		cout << word[1] << endl;

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}