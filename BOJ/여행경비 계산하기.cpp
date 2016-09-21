#include <iostream>
using namespace std;
int min = 10000;
void find_d(int (*arr)[20], int *visit, int now, int cnt,int cost, int max)
{
	if (cnt == max + 1&&now==0)
	{
		if (min > cost)
			min = cost;
		return;
	}
	
	if (cnt < max)
	{	
		int tmp = visit[now];
		visit[now] = cnt;

		for (int i = 0; i < max; i++)
		{
			if (visit[i] == 0)
			{
				find_d(arr, visit, i, cnt + 1, cost + arr[now][i], max);
			}
		}
		visit[now] = tmp;
	}
	else
	{
		find_d(arr, visit, 0, cnt + 1, cost + arr[now][0], max);
	}
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int cnt;
		cin >> cnt;
		int arr[20][20] = { 0 };
		int visit[20] = { 0 };
		for (int i = 0; i < cnt; i++)
		{
			for (int j = 0; j < cnt; j++)
			{
				cin >> arr[i][j];
			}
		}
		min = 10000;
		find_d(arr, visit, 0,1, 0, cnt);
		int sum = min;


		cout << sum << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}