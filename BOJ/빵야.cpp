//#include<iostream>
//
//using namespace std;
//int cnt=0;
//
//void fac(int a, int posi, int seq, int *arr)
//{
//	if (seq == 0)
//	{
//		for (int i = 2; i < a; i++)
//		{
//			arr[i] = 1;
//			fac(a, posi + 1, seq, arr);
//
//		}
//	}
//	else if (seq<=a)
//	{
//		for (int i = 1; i < a; i++)
//		{
//			if (arr[i] != 1&&posi!=i){
//				arr[i] = 1;
//				fac(a, posi + 1, seq, arr);
//			}
//		}
//	}
//	else
//	{
//		cnt++;
//	}
//}
//
//int main()
//{
//	int a;
//	cin >> a;
//	int arr[12] = { 0, };
//
//	fac(a, 0, 0, arr);
//	cout << cnt;
//
//}

/*

VCPP, GPP에서 사용

*/

#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int n;
		cin >> n;
		int sum=9;
		if (n < 4)
		{
			switch (n){
			case 0:
			case 1:
				cout << "0" << endl;
				break;
			case 2:
				cout << "1" << endl;
				break;
			case 3:
				cout << "2" << endl;
				break;
			}

		}
		else
		{
			for (int i = 4; i < n; i++)
			{
				if (i % 2 == 0)
				{
					sum *= i+1;
					sum -= 1;

				}
				else
				{
					sum *= i+1;
					sum += 1;
				}
			}
			cout << sum << endl;
		}

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}	