/*

VCPP, GPP에서 사용

*/

#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */
	int room[10];
	for (int i = 0; i < nCount; i++)
	{
		cin >> room[i];

	}
	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;


		char co[101];
		int cnt = 0;

		for (int i = 1; i <= room[itr]; i++){
			co[i] = 'c';
		}


		for (int i = 1; i <= room[itr]; i++){
			for (int j = 1; i * j <= room[itr]; j++){
				if (co[j*i] == 'c')
					co[j*i] = 'o';
				else
					co[j*i] = 'c';
			}
		}
		for (int i = 1; i <= room[itr]; i++){
			if (co[i] == 'o')
				cnt += 1;
		}
		cout << cnt << endl;



	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}