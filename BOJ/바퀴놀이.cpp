 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		char arr1[33], arr2[33];
		cin >> arr1>>arr2;
		unsigned int num1=0, num2=0;
		int tmp = 1;
		int len1 = 0,len2 = 0;
		for (; arr1[len1] != 0; len1++);
		for (; arr2[len2] != 0; len2++);

		for (int i=len1-1; i >=0; i--)
		{
			if (arr1[i] <= '9')
			{
				num1 += (arr1[i] - 48)*tmp;
			}
			else
			{
				num1 += (arr1[i] - 'A'+10)*tmp;
			}
			tmp *= 16;
		}
		tmp = 1;
		for (int i = len2 - 1; i >= 0; i--)
		{
			if (arr2[i] <= '9')
			{
				num2 += (arr2[i] - 48)*tmp;
			}
			else
			{
				num2 += (arr2[i] - 'A' + 10)*tmp;
			}
			tmp *= 16;
		}

		unsigned int num_tmp = num1;
		int left = -1;
		int right = -1;
		for (int i = 0; i < 32; i++)
		{
			if (num_tmp == num2)
			{
				left = i;
				break;
			}
			int tmp = 0;
			if ((num_tmp & 2147483648) == 2147483648)
				tmp = 1;
			num_tmp = num_tmp << 1;
			if (tmp == 1)
			{
				num_tmp += 1;
				tmp = 0;
			}
		}
		num_tmp = num1;
		for (int i = 0; i < 32; i++)
		{
			if (num_tmp == num2)
			{
				right = i;
				break;
			}
			int tmp = 0;
			if ((num_tmp & 1) == 1)
			tmp = 1;
			num_tmp = num_tmp >> 1;
			if (tmp == 1)
			{
				num_tmp += 2147483648;
				tmp = 0;
			}
		}
		if (left > right)
			cout << right << " Right" << endl;
		else if (left == right&&left != -1)
			cout << left << " Any" << endl;
		else if (left < right)
			cout << left << " Left" << endl;
		else
			cout << "Not possible" << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}