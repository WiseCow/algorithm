//
//#include <iostream>
//using namespace std;
//void mount(int hight)
//{
//	if (hight < 1) return;
//	mount(hight - 1);
//	cout << hight;
//	mount(hight - 1);
//}
//int main()
//{
//	int nCount;		/* 문제의 테스트 케이스 */
//	cin >> nCount;	/* 테스트 케이스 입력 */
//	for (int itr = 0; itr < nCount; itr++)
//	{
//		cout << "#testcase" << (itr + 1) << endl;
//		int num;
//		cin >> num;
//		mount(num);
//		cout << endl;
//	}
//	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
//}



//#include <iostream>
//using namespace std;
//
//int main()
//{
//
//	int nCount;		/* 문제의 테스트 케이스 */
//
//	cin >> nCount;	/* 테스트 케이스 입력 */
//
//	for (int itr = 0; itr < nCount; itr++)
//	{
//
//		cout << "#testcase" << (itr + 1) << endl;
//
//		int arr[10000] = { 0 };
//		arr[0] = 1;
//
//
//		int print, point;
//		cin >> print>>point;
//		int i;
//
//		for (int k = 2; k <= print; k++)
//		{
//			for (i = 0; arr[i] != 0; i++);
//			arr[i] = k;
//			for (int l = i + 1; i > 0; i--, l++)
//			{
//				arr[l] = arr[i - 1];
//			}
//
//
//		}
//		if (arr[point] != 0)
//		{
//			cout << arr[point] << endl;
//		}
//		else
//		{
//			cout << "none" << endl;
//		}
//	}
//
//	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
//
//}

/*

VCPP, GPP에서 사용

*/

#include <iostream>
using namespace std;
void print(int high)
{
	if (high == 1)
		cout << high;
	else
	{
		print(high - 1);
		cout << high;
		print(high - 1);
	}
}

int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int high;
		cin >> high;
		print(high);
		cout << endl;


	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}