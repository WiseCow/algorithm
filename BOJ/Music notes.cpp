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
		int song;
		int beat[10000];
		int note[10000] = { 0, };
		int ques;
		int ans[10000];
		cin >> song;
		cin >> ques;
		for (int i = 0; i < song; i++)
		{
			cin >> beat[i];
			if (i == 0)
				note[i] = beat[i];
			else
				note[i] = beat[i] +	note[i - 1];

		}
		for (int i = 0; i < ques; i++)
		{
			cin >> ans[i];

		}



		cout << "#testcase" << (itr + 1) << endl;
		for (int i = 0; i < ques; i++)
		{
			for (int j = song-1; j >= 0; j--)
			{
				if (ans[i] < note[j])
				{
					if (j == 0)
						cout << 1 << endl;
					else
					continue;
				}
				else if (ans[i]==note[j])
				{
					cout << j+2<<endl;
					break;
				}
				else
				{
					cout << j + 2 << endl;
					break;
				}
				
			}
		}
		
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}