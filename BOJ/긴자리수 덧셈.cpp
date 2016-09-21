 
#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		char arr1[100] = { 0, }, arr2[100] = { 0, };
		char rev1[100] = { 0, }, rev2[100] = { 0, };
		char res[101] = { 0, };
		int arr1_len = 0, arr2_len = 0;
		cin >> arr1;
		cin >> arr2;
		for (int i = 0;; i++)
		{
			arr1_len = i;
			if (arr1[i] == 0)
				break;
		}
		for (int i = 0;; i++)
		{
			arr2_len = i;
			if (arr2[i] == 0)
				break;
		}
		for (int i = 0; i < arr1_len; i++)
		{
			rev1[i] = arr1[arr1_len - 1 - i];
		}
		for (int i = 0; i < arr2_len; i++)
		{
			rev2[i] = arr2[arr2_len - 1 - i];
		}
		int len_max;
		if (arr1_len - arr2_len>0)
			len_max = arr1_len;
		else if (arr1_len - arr2_len == 0)
			len_max = arr1_len;
		else
			len_max = arr2_len;;


		bool flag = 0;

		for (int i = 0; i < len_max; i++)
		{
			if (rev1[i] != 0 && rev2[i] != 0){
				if (flag == false){
					int j = rev1[i] - 48 + rev2[i] - 48;
					if (j>9)
					{
						flag = true;
						j -= 10;
					}
					res[i] = j + 48;
				}
				else
				{
					flag = 0;
					int j = rev1[i] - 48 + rev2[i] + 1 - 48;
					if (j > 9)
					{
						flag = true;
						j -= 10;
					}
					res[i] = j + 48;
				}
			}
			else if (rev1[i] != 0)
			{
				if (flag == true)
				{
					flag = 0;
					int j = rev1[i] - 48 + 1;
					if (j>9)
					{
						flag = true;
						j -= 10;
					}
					res[i] = j + 48;
				}
				else
				{
					res[i] = rev1[i];
				}
			}
			else
			{
				if (flag == true)
				{
					flag = 0;
					int j = rev2[i] - 48 + 1;
					if (j>9)
					{
						flag = true;
						j -= 10;
					}
					res[i] = j + 48;
				}
				else
				{
					res[i] = rev2[i];
				}

			}
		}
		if (flag == true)
		{
			res[len_max] = 49;
			len_max++;
			
		}

		for (int i = len_max - 1; i >= 0; i--)
		{
			cout << res[i];
		}
		cout << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}