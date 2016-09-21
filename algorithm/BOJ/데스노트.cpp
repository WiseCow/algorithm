#include<iostream>
#include<algorithm>
using namespace std;
int input[1001];
int sol[1001][1001];
int last[1000][2];
int n, m;

int solve(int a, int b)
{
	if (a == n + 1)
		return 0;

	if (b > m)
	{
		if (b == m + 1)
			return a + solve(a, 1);
		else if (b == m + 2)
			return solve(a, 1);
	}


	int& in = sol[a][b];
	if (in != -1)
		return in;
	else
		in = 987654321;



	if (b + input[a] - 1 <= m)
	{
		in = min(in, solve(a + 1, b + input[a] + 1));
	}

	in = min(in, (m - b + 2)*(m - b + 2) + solve(a, 1));

	return in;

}
int main()
{
	scanf("%d %d", &n,&m);
	for (int i = 1; i < n; i++)
		scanf("%d", &input[i]);

	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
			sol[i][j] = -1;

	printf("%d\n", solve(1, 1));
	
}
//#include <stdio.h>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int n, m, arr[1111], cache[1111][1111];
//const int INF = 987654321;
//int sol(int i, int start)
//{
//	if (i == n + 1)
//		return 0;
//
//	if (start > m)
//	{
//		if (start == m + 1)
//			return 1 + sol(i, 1);
//		else if (start == m + 2)
//			return sol(i, 1);
//	}
//
//	int& ret = cache[i][start];
//	if (ret != -1)
//		return ret;
//	ret = INF;
//
//	if (start + arr[i] - 1 <= m)
//		ret = min(ret, sol(i + 1, start + arr[i] + 1));
//
//	ret = min(ret, (m - start + 2)*(m - start + 2) + sol(i, 1));
//	return ret;
//}
//
//int main()
//{
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <= n; i++)
//		scanf("%d", &arr[i]);
//
//	for (int i = 0; i<1111; i++)
//		for (int j = 0; j<1111; j++)
//			cache[i][j] = -1;
//	printf("%d\n", sol(1, 1));
//}
//
//
////#include<iostream>
////using namespace std;
////int input[1001];
////long long sol[1001][2];
////int last[1000][2];
////
////int main()
////{
////	int n,m;
////	scanf("%d %d", &n,&m);
////
////
////	for (int i = 1; i <= n; i++)
////	{
////		scanf("%d", &input[i]);
////		if (i == 1)
////		{
////			int k = m - input[i];
////			last[i][0] = k;
////			last[i][1] = k;
//// 		}
////		else
////		{
////
////			if (last[i - 1][0] - 1 >= input[i])
////			{
////				sol[i][0] = sol[i - 1][0];
////				last[i][0] = last[i - 1][0] - input[i] - 1;
////			}
////			else
////			{
////				sol[i][0] = sol[i - 1][0] + last[i-1][0]*last[i - 1][0];
////				last[i][0] = m - input[i];
////			}
////
////			sol[i][1] = sol[i - 1][0]+last[i-1][0]*last[i-1][0];
////			last[i][1] = m - input[i];
////
////			
////			int  tmp;
////			int tmp1;
////			if (last[i - 1][1] - 1 >= input[i])
////			{
////				tmp = sol[i - 1][1];
////				tmp1 = last[i - 1][1] - input[i] - 1;
////			}
////			else
////			{
////				tmp = sol[i - 1][1] + last[i - 1][1] * last[i - 1][1];
////				tmp1 = m - input[i];
////			}
////			if (sol[i][0] > tmp)
////			{
////				sol[i][0] = tmp;
////				last[i][0] = tmp1;
////			}
////			else if (sol[i][0] == tmp&&last[i][0]<tmp1)
////			{
////				last[i][0] = tmp1;
////			}
////
////			tmp = sol[i - 1][1] + last[i - 1][1] * last[i - 1][1];
////			tmp1 = m - input[i];
////
////
////			if (sol[i][1] > tmp)
////			{
////				sol[i][1] = tmp;
////				last[i][1] = tmp1;
////			}
////			else if (sol[i][1] == tmp&&last[i][1] < tmp1)
////			{
////				last[i][1] = tmp1;
////
////			}
////			cout << endl;
////
////		}
////
////
////
////	}
////
////
////	return 1;
////
////
////
////
////
////
////
////
////
////}