#include <iostream>
using namespace std;

char arr[1000000] = { 0, };
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int N, P, res;

		cin >> N >> P;
		res = N*N%P;
		while (1)
		{
			if (arr[res] != 1)
				arr[res] = 1;
			else
				break;
			res = res*N%P;
		}

		int flag = 0;
		while (1)
		{
			if (arr[res] == 1)
			{
				arr[res] = 2;
				flag++;
				res = res*N%P;
			}
			else
				break;
		}

		cout << flag<<endl;

		for (int i = 0; i < 1000000; i++)
		{
			arr[i] = 0;
		}

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}