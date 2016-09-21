

#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		char str[10], strtmp[10],strtmp2[10], tmp;
		cin >> str;

		int len = strlen(str);
		int max=0, max_p=10;
		int min=9,min_p=10;

		for (int i = 0; i < len; i++)
		{
			strtmp[i] = str[i];
			strtmp2[i] = str[i];

			if (str[i] - 48 >= max)
			{
				max = str[i] - 48;
				max_p = i;
			}
			if (str[i] - 48 <= min&&str[i] - 48!=0)
			{
				min = str[i] - 48;
				min_p = i;
			}
		}
		if (max_p != 10)
		{
			tmp = strtmp[max_p];
			strtmp[max_p] = strtmp[0];
			strtmp[0] = tmp;
		}
		strtmp[len] = 0;

		if (min_p != 10)
		{
			tmp = strtmp2[min_p];
			strtmp2[min_p] = strtmp2[0];
			strtmp2[0] = tmp;
			
		}
		strtmp2[len] = 0;
		cout <<strtmp2<<" "<< strtmp << endl;;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}