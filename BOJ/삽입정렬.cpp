
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int cnt;
		cin >> cnt;

		int arr[100];

		for (int i = 0; i < cnt; i++)
		{
			int in;
			cin >> in;
			if (i == 0)
				arr[0] = in;
			else
			{
				int j;
				for (j = i; (j>0) && arr[j - 1] > in;)
				{
					arr[j] = arr[j - 1];
					j--;
				}
				arr[j] = in;
			}
		}
		for (int i = 0; i < cnt; i++)
			cout << arr[i] << " ";
		cout << endl;
	}return 0;
}