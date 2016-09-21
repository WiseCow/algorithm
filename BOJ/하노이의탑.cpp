 
#include <iostream>
using namespace std;
int flag = 0;
void hanoi(int n, int a, int b)
{
	int c;
	if (n <= 1)
	{
		flag++;
	}
	else
	{
		c = 15 - a - b;
		hanoi(n - 1, a, c);
		flag++;
		hanoi(n - 1, c, b);
	}
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		int num;
		cout << "#testcase" << (itr + 1) << endl;
		cin >> num;
		
		hanoi(num, 1, 2);
		cout << flag << endl;

		flag = 0;
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}