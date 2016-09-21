//#include <iostream>
//using namespace std;
//int result = 0;
//
//void check(int *arr, int* narr, int n, int k, int sum)
//{
//	narr[sum] = k + 1;
//	result = sum;
//
//	if (k == 0)
//	{
//		return;
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		if (narr[sum + arr[i]] < k)
//		{
//			check(arr, narr, n, k - 1, sum + arr[i]);
//		}
//	}
//}
//
//void selection(int *arr, int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		int min = i;
//		for (int j = i + 1; j < n; j++)
//		{
//			if (arr[min] > arr[j])
//			{
//				min = j;
//			}
//		}
//		int tmp = arr[min];
//		arr[min] = arr[i];
//		arr[i] = tmp;
//	}
//}
//
//int main()
//{
//
//	int nCount;      /* 문제의 테스트 케이스 */
//
//	cin >> nCount;   /* 테스트 케이스 입력 */
//
//	for (int itr = 0; itr<nCount; itr++)
//	{
//
//		cout << "#testcase" << (itr + 1) << endl;
//
//		/*
//
//		알고리즘이 들어가는 부분
//
//		*/
//
//		int k, n;
//		cin >> k >> n;
//		int num[200000] = { 0, };
//		int arr[205] = { 0, };
//
//		for (int i = 0; i < n; i++)
//		{
//			cin >> arr[i];
//		}
//
//		selection(arr, n);
//
//		check(arr, num, n, k, 0);
//
//		int i;
//		for (i = 1; num[i] != 0; i++);
//
//		cout << i - 1 << endl;
//	}
//
//	return 0;   /* 반드시 return 0으로 해주셔야합니다. */
//
//}

 
#include <iostream>
using namespace std;

void find(int *arr, int *res, int n, int k, int sum)
{
	res[sum] = k + 1;

	if (k == 0)
		return;

	for (int i = 0; i < n; i++)
	{
		if (res[sum + arr[i]] < k)
		{
			find(arr, res, n, k - 1, sum + arr[i]);
		}
	}

}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int use, num;
		cin >> use >> num;
		int arr[201] = { 0 };
		for (int i = 0; i < num; i++)
		{
			cin >> arr[i];
		}
		for (int i = 0; i < num - 1; i++)
		{
			for (int j = 0; j < num - i - 1; j++)
			{
				if (arr[j]>arr[j + 1])
				{
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
		int res[100000] = { 0 };

		find(arr, res, num,use, 0);

		for (int i = 0;; i++)
			if (res[i] == 0){
				cout << i - 1 << endl;
				break;
			}
			
		

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}