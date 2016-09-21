 
#include <iostream>
using namespace std;

int gcm(int a, int b)
{
	if (b == 0)return a;
	else gcm(b, a%b);
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int a, b;
		cin >> a >> b;
		if (gcm(a, b) == 1)
			cout << "yes" << endl;
		else
			cout << "no" << endl;


	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}