#include <iostream>
using namespace std;

int res = 0;
void find(int(*arr)[101],int *chk, int x, int y,int max, int count)
{
	if (chk[x] == 0)
	{
		chk[x] = 1;
		count++;
		if (x == y)
			res = count;
		else
		{
			for (int i = 1; i <= max; i++)
			{
				if (arr[x][i] == 1)
				{
					arr[x][i] = 2;
					find(arr,chk, i, y, max, count);
				}
			}
		}
	}
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int arr[101][101] = { 0 };

		int man;
		cin >> man;
		int x, y;
		cin >> x >> y;
		int cnt;
		cin >> cnt;
		for (int i = 0; i < cnt; i++)
		{
			int a, b;
			cin >> a >> b;
			arr[a][b] = 1;
			arr[b][a] = 1;
		}
		int chk[100] = { 0 };
		find(arr, chk,x, y, man, -1);

		if (res == 0)
			cout << "-1" << endl;
		else
			cout << res << endl;
		res = 0;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}