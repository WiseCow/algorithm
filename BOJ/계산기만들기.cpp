#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int A, B;
		char cmd[2];
		cin >> A >> B >> cmd;

		switch (cmd[0])
		{
		case '+':
			cout << A + B << endl;
			break;

		case '-':
			cout << A - B << endl;
			break;

		case '*':
			cout << A * B << endl;
			break;

		case '/':
			if (B == 0)
				cout << "-9999" << endl;
			else
				cout << A / B << endl;
			break;
		}

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}