
#include <iostream>
using namespace std;
int main()
{
	char arr[8][7] = { { "000000" }, { "001111" }, { "010011" }, { "011100" }, { "100110" }, { "101001" }, { "110101" }, { "111010" } };
	char ans[9] = { "ABCDEFGH" };
	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int num;
		cin >> num;
		char msg[100];
		cin >> msg;
		char res[100] = { 0, };
		bool flag = 0;
		int cnt = 0;
		for (int i = 0; i < num; i++)
		{

			for (int j = 0; j < 8; j++)
			{
				int flag = 0;
				for (int k = 0; k < 6; k++)
				{
					if (arr[j][k] == msg[i * 6 + k])
						flag++;
				}
				if (flag >= 5)
					res[i] = ans[j];
			}
			if (res[i] == 0)
			{
				cnt = i;
				flag = 1;
				break;
			}

		}
		if (flag == 0)
		{
			res[num] = 0;

			cout << res << endl;
		}
		else
			cout << cnt + 1 << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
