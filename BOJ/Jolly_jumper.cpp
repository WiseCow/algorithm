
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{
		int cnt;
		cin >> cnt;
		int arr[10000];
		for (int i = 0; i < cnt; i++)
		{
			cin >> arr[i];
		}
		int ans[10000];
		for (int i = 0; i < cnt - 1; i++)
		{
			ans[i] = arr[i] - arr[i + 1];
			ans[i] < 0 ? ans[i] *= -1 : ans[i];
		}

		for (int i = 0; i < cnt - 2; i++)
		for (int j = 0; j < cnt - i - 2; j++)
		{
			if (ans[j]>ans[j + 1])
			{
				int tmp = ans[j];
				ans[j] = ans[j + 1];
				ans[j + 1] = tmp;

			}
		}

		int flag = 0;

		cout << "#testcase" << (itr + 1) << endl;
		for (int i = 0; i < cnt - 2; i++)
		{
			if (ans[i + 1] - ans[i] != 1)
				flag = 1;
			if (flag == 1)break;
		}
		if (flag == 0)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;


		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}