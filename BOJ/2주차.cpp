
//////// 
////////
////////#include <iostream>
////////using namespace std;
////////int main()
////////{
////////
////////	int nCount;		/* 문제의 테스트 케이스 */
////////
////////	cin >> nCount;	/* 테스트 케이스 입력 */
////////
////////	for (int itr = 0; itr<nCount; itr++)
////////	{
////////
////////		cout << "#testcase" << (itr + 1) << endl;
////////		char arr[100][100];
////////		for (int i = 0;; i++)
////////		{
////////			cin >> arr[i];
////////			if (arr[i][0] == 'E'&&arr[i][1] == 'N'&&arr[i][2] == 'D'&&arr[i][3]==0)
////////			{
////////
////////				break;
////////			}
////////
////////		}
////////		for (int i = 0;;i++)
////////		{
////////			if (arr[i][0] == 'E'&&arr[i][1] == 'N'&&arr[i][2] == 'D'&&arr[i][3] == 0)
////////			{
////////
////////				break;
////////			}
////////			else{
////////				int j = 0;
////////				for (j = 0; j < 100; j++)
////////				{
////////					if (arr[i][j] == 0)
////////						break;
////////				}
////////				for (j -= 1; j >= 0; j--)
////////				{
////////					printf("%c", arr[i][j]);
////////				}
////////				cout << endl;
////////			}
////////		}
////////		
////////	}
////////
////////	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
////////
////////}
//////
///////*
//////
//////VCPP, GPP에서 사용
//////
//////*/
//////
//////#include <iostream>
//////using namespace std;
//////int main()
//////{
//////
//////	int nCount;		/* 문제의 테스트 케이스 */
//////
//////	cin >> nCount;	/* 테스트 케이스 입력 */
//////
//////	for (int itr = 0; itr < nCount; itr++)
//////	{
//////
//////		cout << "#testcase" << (itr + 1) << endl;
//////
//////		char arr[101] = { 0, };
//////
//////		cin >> arr;
//////		int n, m;
//////		cin >> n >> m;
//////		int pos = 0;
//////		char ans[50][5];
//////		int xx = 0;
//////		int maxx = 30;
//////		for (int i = 0; i < 50; i++)
//////		{
//////			int first = pos;
//////			for (; arr[pos] != '-'&&arr[pos] != 0; pos++);
//////			if (pos - first > 4)
//////			{
//////				xx = 1;
//////				cout << "INPUT ERROR!" << endl;
//////				break;
//////
//////			}
//////			if (pos - first == 0)
//////			{
//////				if (maxx > i)
//////					maxx = i;
//////
//////				ans[i][0] = '0';
//////				ans[i][1] = '0';
//////				ans[i][2] = '0';
//////				ans[i][3] = '0';
//////				ans[i][4] = 0;
//////
//////			}
//////			else
//////			{
//////				bool flag = 0;
//////				char res[5];
//////				for (int j = 3, k=1; j >= 0; j--,k++)
//////				{
//////					res[j] = arr[pos-k];
//////					if (pos - k < 0)
//////						res[j] = '0';
//////					if (arr[pos - k] == '-')
//////						flag = 1;
//////					if (flag == 1)
//////						res[j] = '0';
//////
//////				}
//////				flag = 0;
//////				ans[i][0] = res[0];
//////				ans[i][1] = res[1];
//////				ans[i][2] = res[2];
//////				ans[i][3] = res[3];
//////				ans[i][4] = 0;
//////
//////			}
//////
//////			pos++;
//////		}
//////		/*if (maxx != 10)
//////		{
//////			if (maxx == 1)
//////			{
//////				for (int i = 0; i < 4; i++)
//////				{
//////					ans[3][i] = ans[0][i];
//////					ans[0][i] = '0';
//////				}
//////			}
//////			else if (maxx == 2)
//////			{
//////				for (int i = 0; i < 4; i++)
//////				{
//////					ans[2][i] = ans[0][i];
//////					ans[3][i] = ans[1][i];
//////					ans[0][i] = '0';
//////					ans[1][i] = '0';
//////
//////				}
//////			}
//////			else if (maxx == 3)
//////			{
//////				for (int i = 0; i < 4; i++)
//////				{
//////					
//////					ans[3][i] = ans[2][i];
//////					ans[2][i] = ans[1][i];
//////					ans[1][i] = ans[0][i];
//////					ans[0][i] = '0';
//////				}
//////			}
//////
//////		}*/
//////
//////		//if (arr[pos+1]!=0)
//////		//{
//////		//	cout << "INPUT ERROR!" << endl;
//////		//	break;
//////		//}
//////
//////
//////		if (xx != 1)
//////		{
//////			for (int i = 0; i < 4; i++)
//////			{
//////				int a = ans[m-1][i]-48;
//////				a += n;
//////				a %= 10;
//////				cout << a;
//////			}
//////			cout<<endl;
//////		}
//////
//////
//////
//////	}
//////
//////	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
//////
//////}
//// 
////
////#include <iostream>
////using namespace std;
////
////
////void _find(char(*arr)[101], int (*res)[100], int x, int y, int x_p, int y_p, int cnt)
////
////{
////	if (arr[x_p][y_p] == '1' && (res[x_p][y_p] > cnt || res[x_p][y_p] == 0))res[x_p][y_p] = cnt;
////	else return;
////	if (x_p - 1 >= 0)_find(arr, res, x, y, x_p-1, y_p, cnt + 1);
////	if (x_p + 1 < x)_find(arr, res, x, y, x_p+1, y_p, cnt + 1);
////	if (y_p - 1 >= 0)_find(arr, res, x, y, x_p, y_p-1, cnt + 1);
////	if (y_p + 1 < y)_find(arr, res, x, y, x_p, y_p+1, cnt + 1);
////}
////
////int main()
////{
////
////	int nCount;		/* 문제의 테스트 케이스 */
////	cin >> nCount;	/* 테스트 케이스 입력 */
////	for (int itr = 0; itr<nCount; itr++)
////	{
////		cout << "#testcase" << (itr + 1) << endl;
////		int x, y;
////		cin >> y >> x;
////		char arr[101][101];
////		int res[100][100] = { 0, };
////		for (int i = 0; i < x; i++)
////		{
////			cin >> arr[i];
////		}
////		int x_p, y_p;
////		cin >> y_p>> x_p;
////		_find(arr, res, x, y, x_p-1, y_p-1, 3);
////		int cnt = 0;
////		int max = 0;
////		for (int i = 0; i < x; i++)
////		{
////			for (int j = 0; j < y; j++)
////			{
////				if (res[i][j] > max)max = res[i][j];
////				if (arr[i][j] == '1'&&res[i][j] == 0)cnt++;
////			}
////		}
////		cout << max << " " << cnt << endl;
////	}
////
////	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
////
////}
//
//
///*
//
//VCPP, GPP에서 사용
//
//*/
//
//#include <iostream>
//using namespace std;
//int main()
//{
//
//	int nCount;		/* 문제의 테스트 케이스 */
//
//	cin >> nCount;	/* 테스트 케이스 입력 */
//
//	for (int itr = 0; itr<nCount; itr++)
//	{
//
//		cout << "#testcase" << (itr + 1) << endl;
//
//		int arr[100][100] = { 0, }; 
//		int cnt;
//		cin >> cnt;
//
//		for (int i = 0; i < cnt; i++)
//		{
//			int x,y;
//			cin >> x >> y;
//
//			for (int k = x - 1; k < x + 9; k++)
//			{
//				for (int l = y - 1; l < y + 9; l++)
//				{
//
//					if (k>-1 && k<100 && l>-1 && l < 100)arr[k][l] = 1;
//				}
//			}
//		}
//		int flag = 0;
//		for (int i = 0; i < 100;i++)
//			for (int j = 0; j < 100; j++)
//			{
//				if (arr[i][j] == 1)flag++;
//			}
//		cout <<flag<<endl;
//
//
//	}
//
//	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
//
//}



#include <iostream>
using namespace std;
int  _abs(int a)
{
	if (a > 0)
		return a;
	else
		return -a;

}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int num;
		int arr[100000];
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < num; i++)//소트방법만바꾸면됨
		{
			int min = i;
			for (int j = i + 1; j < num; j++)
			{
				if (arr[j] < arr[min]) min = j;
			}
			int tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}


		int l_flag = 0, r_flag = num - 1;
		int min = _abs(arr[l_flag] + arr[r_flag]);
		int x = arr[l_flag], y = arr[r_flag];
		while (1)
		{
			if (l_flag == r_flag)break;
			int sum = _abs(arr[l_flag] + arr[r_flag]);
			if (sum < min)
			{

				min = sum;
				x = arr[l_flag];
				y = arr[r_flag];
				if (sum == 0)
				{
					break;
				}
			}
			sum = arr[l_flag] + arr[r_flag];
			if (sum < 0)
				l_flag++;

			else
				r_flag--;


		}

		cout << x << " " << y << endl;;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}