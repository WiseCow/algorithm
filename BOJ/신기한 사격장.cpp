 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int arr[10][10];
		for (int i = 0; i < 6;i++)
		for (int j = 0; j < 6; j++)
		{
			cin >> arr[i][j];

		}
		int sum = 0;
		for (int i = 0; i < 6; i++){
			for (int j = 0; j < 6; j++)
			{
				int res= arr[i][j];
				if (i - 1>=0)res += arr[i - 1][j];
				if (j - 1>=0)res += arr[i][j-1];
				if (i + 1<6)res += arr[i + 1][j];
				if (j + 1<6)res += arr[i][j+1];
				if (res>sum)
					sum = res;
			}
		}
		cout << sum<<endl;;


	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}