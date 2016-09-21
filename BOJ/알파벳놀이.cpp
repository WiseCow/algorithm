#include <iostream>
using namespace std;

void find(int *chk, int cnt, int now, char *print)
{
	if (cnt == now)
	{
		print[now] = 0;
		cout << print << endl;
		return;
	}
	else
	{
		for (int n = 0; n < 26; n++)
		{
			if (chk[n]>0)
			{
				print[now] = n + 97;
				chk[n]--;
				find(chk, cnt, now+1, print);
				chk[n]++;
			}
		}
	}
}
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		char arr[11] = { 0 };
		cin >> arr;
		int chk[26] = { 0 };
		int cnt = 0;
		for (cnt = 0; arr[cnt] != 0; cnt++)
		{
			chk[arr[cnt] - 97]++;
		}
		char print[11] = { 0};
		for (int n = 0; n < 26; n++)
		{
			if (chk[n]>0)
			{
				print[0] = n + 97;
				chk[n]--;
				find(chk, cnt, 1, print);
				chk[n]++;
			}
		}


	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}