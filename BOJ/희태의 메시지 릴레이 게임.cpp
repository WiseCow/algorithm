#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		char man[100] = { 0 };
		char msg[100] = { 0 };
		cin >> man >> msg;
		int msg_len=0;
		for (; msg[msg_len] != 0; msg_len++);
		int man_p = 0;
		for (; man[man_p] != 0; man_p++);

		char ch;
		char cpy[100] = { 0 };
		int half = msg_len/2;
		while (man_p != -1)
		{
			
			switch (man[man_p])
			{
				
			case 'J':
				ch = msg[msg_len - 1];
				for (int i = msg_len - 1; i > 0; i--)
				{
					msg[i] = msg[i - 1];
				}
				msg[0] = ch;
				break;

			case 'C':
				
				ch = msg[0];
				for (int i = 1; i < msg_len; i++)
				{
					msg[i - 1] = msg[i];
				}
				msg[msg_len - 1] = ch;
				break;

			case 'E':

				if (msg_len % 2 == 1){
					for (int i = 0; i < half; i++)
					{
						cpy[i] = msg[i];
					}
					for (int i = 0; i < half; i++)
					{
						msg[i] = msg[half + i + 1];
					}
					for (int i = 0; i < half; i++)
					{
						msg[half + i + 1] = cpy[i];
					}
				}
				else
				{
					for (int i = 0; i < half; i++)
					{
						cpy[i] = msg[i];
					}
					for (int i = 0; i < half; i++)
					{
						msg[i] = msg[half + i];
					}
					for (int i = 0; i < half; i++)
					{
						msg[half + i] = cpy[i];
					}
				}

				break;

			case 'A':
				for (int i = 0; i < half; i++)
				{
					char tmp = msg[i];
					msg[i] = msg[msg_len - 1 - i];
					msg[msg_len - 1 - i] = tmp;	
				}

				break;

			case 'P':
				for (int i = 0; i < msg_len; i++)
				{
					if (msg[i] == '0')
						msg[i] = '9';
					else
					{
						if (msg[i] >= '0'&&msg[i] <= '9')
							msg[i]--;
					}

				}

				break;

			case 'M':
				for (int i = 0; i < msg_len; i++)
				{
					if (msg[i] == '9')
						msg[i] = '0';
					else
					{
						if (msg[i] >= '0'&&msg[i] < '9')
							msg[i]++;
					}

				}
				
				break;
			}
			man_p--;
		}
		cout << msg << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}