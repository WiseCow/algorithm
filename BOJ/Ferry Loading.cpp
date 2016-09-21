#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int meter, car;

		cin >> meter >> car;
		int left[100000], right[100000];
		int le_p = 0, ri_p = 0;
		for (int i = 0; i < car; i++)
		{
			char dis[10];
			int size;
			cin >> size >> dis;
			if (dis[0] == 'l')
			{
				left[le_p++] = size;
			}
			else
			{
				right[ri_p++] = size;
			}
		}


	/*	for (int i = 0; i < le_p-1; i++)
		{
			for (int j = 0; j < le_p-i - 1; j++)
			{
				if (left[j]>left[j + 1])
				{
					int tmp = left[j];
					left[j] = left[j + 1];
					left[j + 1] = tmp;
				}
			}
		}	
		for (int i = 0; i < ri_p - 1; i++)
		{
			for (int j = 0; j < ri_p - i - 1; j++)
			{
				if (right[j]>right[j + 1])
				{
					int tmp = right[j];
					right[j] = right[j + 1];
					right[j + 1] = tmp;
				}
			}
		}*/
		int i = 0, l_cnt = 0;
		while (i < le_p)
		{
			int sum = 0;
			while (sum < meter * 100)
			{
				sum += left[i++];
				if (i >= le_p)
					break;
			}
			if (sum > meter * 100)
			{
				sum -= left[--i];
			}
			l_cnt++;
		}
		i = 0;
		int r_cnt = 0;
		while (i < ri_p)
		{
			int sum = 0;
			while (sum < meter * 100)
			{
				sum += right[i++];
				if (i >= ri_p)
					break;
			}
			if (sum > meter * 100)
			{
				sum -= right[--i];
			}
			r_cnt++;
		}


		if (l_cnt > r_cnt + 1)
		{ 
			r_cnt = l_cnt - 1;
		}
		else if (r_cnt > l_cnt)
		{
			l_cnt = r_cnt;
		}

		cout << l_cnt + r_cnt << endl;
	/*
		if (l_cnt > r_cnt)
		{
			cout << l_cnt * 2 - 1 << endl;
		}
		else if (l_cnt == r_cnt)
		{
			cout << l_cnt * 2 << endl;
		}
		else
		{
			cout << r_cnt * 2 << endl;
		}
*/
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}