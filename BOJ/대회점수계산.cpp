#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int cnt, res = 0, max = 0, min = 10000;
		cin >> cnt;
		for (int i = 0; i < cnt; i++)
		{
			int tmp;
			cin >> tmp;
			res += tmp;
			if (min>tmp)
				min = tmp;
			if (max < tmp)
			{
				max = tmp;
			}
		}
		res = res - min - max;
		cout << res / (cnt - 2) << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}