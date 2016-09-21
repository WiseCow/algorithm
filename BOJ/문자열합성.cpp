#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

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

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}