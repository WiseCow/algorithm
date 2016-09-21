//https://www.acmicpc.net/problem/1236
#include<iostream>
using namespace std;
char arr[60][60];
int main()
{
	int x, y;
	cin >> x >> y;

	for (int i = 0; i < x; i++)
	{
		cin >> arr[i];
	}

	int xc = 0, yc = 0;
	for (int i = 0; i < x; i++)
	{
		bool chk = 0;
		for (int j = 0; j < y; j++)
		{
			if (arr[i][j] == 'X')
			{
				chk = 1;
			}
		}
		if (chk == 0)
		{
			xc++;
		}
	}
	for (int i = 0; i < y; i++)
	{
		bool chk = 0;
		for (int j = 0; j < x; j++)
		{
			if (arr[j][i] == 'X')
			{
				chk = 1;
			}
		}
		if (chk == 0)
		{
			yc++;
		}
	}

	if (xc > yc)
		cout << xc << endl;
	else
		cout << yc << endl;
}



//#include<iostream>
//using namespace std;
//char arr[60][60];
//
//int mx, my;
//int maxx=987654321;
//void find(int x,int y,int cnt)
//{
//	bool chk = 0;
//	if (arr[x][y] == '.')
//	{
//		cnt++;
//		chk = 1;
//		arr[x][y] = 'X';
//		bool is = 0;
//		for (int i = 0; i < mx; i++)
//		{
//			if (i!=x&&arr[i][y] == 'X')
//			{
//				is = 1;
//				break;
//			}
//		}
//		for (int i = 0; is==0&&i < my; i++)
//		{
//			if (i!=y&&arr[x][i] == 'X')
//			{
//				is = 1;
//				break;
//			}
//		}
//		if (is == 0)
//		{
//			if (x == (mx - 1))
//			{
//				if (cnt<maxx)
//					maxx = cnt;
//				
//			}
//			else
//			{
//				for (int i = y; i < my; i++)
//				{
//					find(x + 1, i, cnt);
//				}
//			}
//		}
//		arr[x][y] = '.';
//	}
//	else
//	{
//		if (x == (mx - 1) )
//		{
//			if(cnt<maxx)
//				maxx = cnt;
//		}
//		else {
//			for (int i = y; i < my; i++)
//			{
//				find(x + 1, i, cnt);
//			}
//		}
//	}
//}
//int main()
//{
//	cin >> mx >> my;
//
//	for (int i = 0; i < mx; i++)
//	{
//		cin >> arr[i];
//	}
//
//	int cnt = 0;
//	for (int i = 0; i < my; i++)
//	{
//		find(0, i,cnt);
//	}
//	
//
//	if (maxx != 987654321)
//		cout << maxx << endl;
//	else
//		cout << 0 << endl;
//
//
//}