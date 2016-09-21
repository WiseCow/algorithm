 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int flo, typ;
		cin >> flo >> typ;
		int arr[31][31];
		for (int i = 0; i < flo; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{
				if (j == 0)
				{
					arr[i][j] = 1;
				}
				else if (j == i)
				{
					arr[i][j] = 1;
				}
				else
				{
					arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
				}
			}
		}
		if (typ == 1)
		{
			for (int i = 0; i < flo; i++){
				for (int j = 0; j < i+1; j++)
				{
					cout << arr[i][j] << " ";

				}
				cout << endl;
			}
		}
		else if (typ == 2)
		{
			for (int i = flo - 1; i>=0; i--)
			{
				for (int j = 0; j < i+1; j++)
					cout << arr[i][j] << " ";
				cout << endl;
			}
 
		}
		else
		{
			for (int i = flo - 1; i >= 0; i--){
				for (int j = flo - 1; j >= i; j--)
				{
					cout << arr[j][i] << " ";
				}
				cout << endl;
			}

		}
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}