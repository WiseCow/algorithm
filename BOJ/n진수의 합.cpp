#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int jinsu;
		char arr[100] = { 0, };
		char arr1[100] = { 0, };
		cin >> jinsu;
		cin >> arr;
		cin >> arr1;
		int cnt;
		long long res = 0;
		int ups = 1;
		if (jinsu < 10)
		{
			for (cnt = 0; arr[cnt] != 0; cnt++);

			for (int i = cnt - 1; i >= 0; i--, ups *= jinsu)
			{
				res += ups * (arr[i] - 48);
			}
			for (cnt = 0; arr1[cnt] != 0; cnt++);
			ups = 1;
			for (int i = cnt - 1; i >= 0; i--, ups *= jinsu)
			{
				res += ups * (arr1[i] - 48);
			}
		}
		else
		{
			for (cnt = 0; arr[cnt] != 0; cnt++);

			for (int i = cnt - 1; i >= 0; i--, ups *= jinsu)
			{
				if (arr[i]>47 && arr[i]<60)
					res += ups * (arr[i] - 48);
				else
				{
					if (arr[i] == 'A')
						res += ups * 10;
					else if (arr[i] == 'B')
						res += ups * 11;

					else if (arr[i] == 'C')
						res += ups * 12;

					else if (arr[i] == 'D')
						res += ups * 13;

					else if (arr[i] == 'E')
						res += ups * 14;

					else if (arr[i] == 'F')
						res += ups * 15;

				}
			}
			for (cnt = 0; arr1[cnt] != 0; cnt++);
			ups = 1;
			for (int i = cnt - 1; i >= 0; i--, ups *= jinsu)
			{
				if (arr1[i]>47 && arr1[i]<60)
					res += ups * (arr1[i] - 48);
				else
				{
					if (arr1[i] == 'A')
						res += ups * 10;
					else if (arr1[i] == 'B')
						res += ups * 11;

					else if (arr1[i] == 'C')
						res += ups * 12;

					else if (arr1[i] == 'D')
						res += ups * 13;

					else if (arr1[i] == 'E')
						res += ups * 14;

					else if (arr1[i] == 'F')
						res += ups * 15;

				}
			}

		}
		int k = res;
		int l = 1;
		cout << res << endl;
		for (; l < res; l  *=jinsu);
		l /= jinsu;

		for (; l != 0; l /= jinsu)
		{
			if (jinsu < 10)
			{
				cout<<res/l;
				res %= l;
			}
			else
			{
				if (res / l < 10)
				{
					cout << res / l;
				}
				else if (res / l == 10)
					cout << "A";
				else if (res / l == 11)
					cout << "B";
				else if (res / l == 12)
					cout << "C";
				else if (res / l == 13)
					cout << "D";
				else if (res / l == 14)
					cout << "E";
				else if (res / l == 15)
					cout << "F";
				res %= l;

			}
		}
		cout << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}