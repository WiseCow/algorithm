//#include <iostream>
//
//using namespace std;
//
//int Result = 0;
//void XX(int *arr, int idx, int sum, int pivot, int n)
//{
//	if (idx > n)
//		return;
//	if (sum > pivot)
//		return;
//	if (sum == pivot)
//	{
//		Result++; return;
//	}
//
//	XX(arr, idx + 1, sum + arr[idx], pivot, n);
//	XX(arr, idx + 1, sum, pivot, n);
//}
//
//int main(void)
//{
//	int n;
//	cin >> n;
//	int arr[100] = { 0, };
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//		sum += arr[i];
//	}
//
//	if (sum % 2 != 0)
//	{
//		cout << "impossible" << endl;
//	}
//	else
//	{
//		XX(arr, 0, 0, sum / 2, n);
//		if (Result == 0) cout << "impossible" << endl;
//		else cout << Result << endl;
//
//	}
//
//	return 0;
//}

#include <iostream>
using namespace std;

int result = 0;
void find(int *arr, int index, int pivot, int sum, int cnt)
{
	if (index > cnt)
		return;
	if (sum > pivot)
		return;
	if (sum == pivot)
	{
		result++;
		return;
	}
	else
	{
		find(arr, index + 1, pivot, sum + arr[index], cnt);
		find(arr, index + 1, pivot, sum, cnt);

	}

}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int cnt;
		int arr[40];
		int sum = 0;
		cin >> cnt;
		for (int i = 0; i < cnt; i++)
		{
			cin >> arr[i];
			sum += arr[i];

		}


		if (sum % 2 == 1)
			cout << "impossible" << endl;
		else
		{
			find(arr, 0, sum / 2, 0, cnt);
			if (result == 0)
				cout << "impossible" << endl;
			else
				cout << result << endl;

		}
		result = 0;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}

