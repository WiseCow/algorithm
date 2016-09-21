/*

VCPP, GPP에서 사용

*/

#include <iostream>
using namespace std;
void _find(int y, int x, int x_p, int y_p, int(*map)[101], int(*res)[101], int cnt)
{
	if (map[x_p][y_p] == 1 && (res[x_p][y_p] == 0 || res[x_p][y_p] > cnt))
		res[x_p][y_p] = cnt;
	else
		return;
	if (x_p - 1 >= 0)_find(y, x, x_p - 1, y_p, map, res, cnt + 1);
	if (x_p + 1 < x) _find(y, x, x_p + 1, y_p, map, res, cnt + 1);
	if (y_p - 1 >= 0)_find(y, x, x_p, y_p - 1, map, res, cnt + 1);
	if (y_p + 1 < y) _find(y, x, x_p, y_p + 1, map, res, cnt + 1);
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int x, y;
		cin >> y >> x;
		int arr[101][101] = { 0, };
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
				cin >> arr[i][j];
		}
		int x_p, y_p;
		cin >> x_p >> y_p;

		int res[101][101] = { 0, };
		_find(y, x, y_p - 1, x_p - 1, arr, res, 1);
		int _max = 0;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			if (res[i][j]>_max)
				_max = res[i][j];
		}
		cout << _max << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}