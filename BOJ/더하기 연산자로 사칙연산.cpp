 

#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int a, b;
		char add[2];

		cin >> a >> add >> b;
		cout << a << add << b<<"=";
		if (add[0] == '+')
			cout << a + b << endl;
		else if (add[0] == '-')
			cout << a - b << endl;
		else if (add[0] == '/')
			cout << a / b << endl;
		else if (add[0] == '*')
			cout << a * b << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}