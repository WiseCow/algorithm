#include <iostream>
using namespace std;
void marge_sort(int *arr, int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left;
	int res[100005] = { 0 };

	while (i <= mid&&j <= right)
	{
		if (arr[i] < arr[j])
			res[k++] = arr[i++];
		else
			res[k++] = arr[j++];
	}
	if (i > mid)
	{
		while (j <= right)
		{
			res[k++] = arr[j++];
		}
	}
	else
	{
		while (i <= mid)
		{
			res[k++] = arr[i++];
		}
	}
	for (int i = left; i <= right; i++)
	{
		arr[i] = res[i];
	}
}
void marge(int *arr, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		marge(arr, left, mid);
		marge(arr, mid + 1, right);
		marge_sort(arr, left, mid, right);
	}
}
int _abs(int a)
{
	if (a < 0)
		return -a;
	else
		return a;
}

int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int cnt;
		cin >> cnt;
		int arr[100005] = { 0 };
		for (int i = 0; i < cnt; i++)
		{
			cin >> arr[i];
		}
		marge(arr, 0, cnt - 1);


		int min = _abs(arr[0] + arr[cnt - 1]);
		int x = 0, y = cnt - 1;
		int minx = 0, miny = cnt - 1;
		while (1)
		{
			if (x == y)
				break;
			if (arr[y] + arr[x] > 0)
			{
				if (min > _abs(arr[y] + arr[x]))
				{
					min = _abs(arr[y] + arr[x]);
					minx = x, miny = y;
				}
				y--;

			}
			else if (arr[y] + arr[x] == 0)
			{
				min = 0;
				minx = x, miny = y;
				break;
			}
			else
			{
				if (min > _abs(arr[y] + arr[x]))
				{
					min = _abs(arr[y] + arr[x]);
					minx = x, miny = y;
				}
				x++;
			}
		}
		cout << arr[minx] << " " << arr[miny] << endl;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}