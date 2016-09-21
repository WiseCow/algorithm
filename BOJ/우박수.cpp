#include <iostream>
using namespace std;


void find(int num)
{
	if (num == 1){
		cout << 1 << endl;
		return;
	}

	if (num % 2 == 1)
		find(3 * num + 1);
	else
		find(num / 2);
	cout << num << endl;

}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int num;
		cin >> num;
		find(num);

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}