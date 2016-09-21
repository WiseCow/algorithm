
#include <iostream>
using namespace std;

int cnt;
int find_Lan(int(*Lan)[101], int x, int y, int size, int dist)
{
	if (Lan[x][y] == 1)
	{
		Lan[x][y] = 0;
		if (dist == 0)
		{
			cnt = 1;
			if (x - 1 >= 0)find_Lan(Lan, x - 1, y, size, 1);
			if (y - 1 >= 0)find_Lan(Lan, x, y - 1, size, 1);
			if (x + 1 < size)find_Lan(Lan, x + 1, y, size, 1);
			if (y + 1 < size)find_Lan(Lan, x, y + 1, size, 1);

			return cnt*cnt;
		}
		else
		{
			cnt++;
			if (x - 1 >= 0)find_Lan(Lan, x - 1, y, size, 1);
			if (y - 1 >= 0)find_Lan(Lan, x, y - 1, size, 1);
			if (x + 1 < size)find_Lan(Lan, x + 1, y, size, 1);
			if (y + 1 < size)find_Lan(Lan, x, y + 1, size, 1);
		}
	}
	else
		return 0;
}
int find_Yor(int(*Yor)[101], int x, int y, int size, int dist)
{
	if (Yor[x][y] == 2)
	{
		Yor[x][y] = 0;
		if (dist == 0)
		{
			cnt = 1;
			if (x - 1 >= 0)find_Yor(Yor, x - 1, y, size, 1);
			if (y - 1 >= 0)find_Yor(Yor, x, y - 1, size, 1);
			if (x + 1 < size)find_Yor(Yor, x + 1, y, size, 1);
			if (y + 1 < size)find_Yor(Yor, x, y + 1, size, 1);

			return cnt*cnt;
		}
		else
		{
			cnt++;

			if (x - 1 >= 0)find_Yor(Yor, x - 1, y, size, 1);
			if (y - 1 >= 0)find_Yor(Yor, x, y - 1, size, 1);
			if (x + 1 < size)find_Yor(Yor, x + 1, y, size, 1);
			if (y + 1 < size)find_Yor(Yor, x, y + 1, size, 1);
		}
	}
	else
		return 0;
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int size;
		cin >> size;
		int arr[101][101] = { 0, };
		int Lan[101][101] = { 0, };
		int Yor[101][101] = { 0, };
		int Lan_c = 0, Yor_c = 0;


		for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				Lan[i][j] = 1;
			else if (arr[i][j] == 2)
				Yor[i][j] = 2;
		}


		int x = 0, y = 0;

		for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (Lan[i][j] == 1)
			{

				Lan_c += find_Lan(Lan, i, j, size, 0);
			}
			if (Yor[i][j] == 2)
			{

				Yor_c += find_Yor(Yor, i, j, size, 0);
			}
		}

		if (Lan_c > Yor_c)
			cout << "Lancaster " << Lan_c << endl;
		else if (Lan_c == Yor_c)
			cout << "Draw " << Lan_c << endl;
		else
			cout << "York " << Yor_c << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}