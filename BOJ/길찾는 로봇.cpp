 
#include <iostream>
using namespace std;
bool flag = 0;
int x_r, y_r;
void _find(char(*arr)[100], int(*res)[100], int x, int y, int x_p, int y_p, int cnt)
{
	if (res[x_p][y_p]==0)
		res[x_p][y_p] = cnt;
	else
	{
		x_r = x_p;
		y_r =y_p;

		flag = 1;
		return;
	}
	if (arr[x_p][y_p] == 'N')
	{
		if (x_p - 1 < 0)
			return;
		else
			_find(arr, res, x, y, x_p - 1, y_p, cnt+1);
	}
	else if (arr[x_p][y_p] == 'S')
	{
		if (x_p + 1 > x)
			return;
		else
			_find(arr, res, x, y, x_p + 1, y_p, cnt+1);

	}
	else if (arr[x_p][y_p] == 'W')
	{
		if (y_p - 1 < 0)
			return;
		else
			_find(arr, res, x, y, x_p, y_p-1, cnt+1);
	}
	else if (arr[x_p][y_p] == 'E')
	{
		if (y_p + 1 > y)
			return;
		else
			_find(arr, res, x, y, x_p, y_p+1, cnt+1);

	}


}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int x, y, z;
		cin >> x >> y >> z;

		char arr[100][100];
		int res[100][100] = { 0, };
		for (int i = 0; i < x; i++)
		{
			cin >> arr[i];
		}
		_find(arr, res, x, y, 0, z-1, 1);

		int max = 0;
		for (int i = 0; i < x;i++)
		for (int j = 0; j < y; j++)
		{
			if (res[i][j]>max)max = res[i][j];
		}

		if (flag == 0)
		{
			cout << max<< " step(s) to exit"<<endl;;
		}
		else
		{
			cout << res[x_r][y_r] - 1 << " step(s) before a loop of " << max - (res[x_r][y_r] - 1) << " step(s)"<<endl;
		}
		flag = 0;
		x_r = 0;
		y_r = 0;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}