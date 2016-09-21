//https://www.acmicpc.net/problem/1700
#include<iostream>
using namespace std;
int input[101];
int coun[101];
bool is[101];
int main()
{
	int capa, tc;

	scanf("%d %d", &capa, &tc);

	for (int i = 1; i <= tc; i++)
	{	
		scanf("%d", &input[i]);
		coun[input[i]]++;
	}
	int point = 1;
	int cnt = 0;
	for (; point <= tc; point++)
	{
		if (cnt == capa) break;
		coun[input[point]]--;
		if (is[input[point]])
		{
			continue;
		}
		else
		{
			is[input[point]] = 1;
			cnt++;
		}

	}
	if (point == tc + 1)
	{
		cout << 0 << endl;
		return 0;
	}

	int ans = 0;
	for (;point<=tc;point++)
	{
		coun[input[point]]--;
		if (is[input[point]] == 1)
			continue;
		int last=0, what;
		for (int i = 1; i <= tc; i++)
		{
			if (is[i])
			{
				bool chk = 0;
				int tlast;
				for (int p = point + 1; p <= tc; p++)
				{
					if (input[p] == i)
					{
						chk = 1;
						if (last < p)
						{
							last = p;
							what = input[p];
						}
						break;
					}
				}
				if (chk== 0)
				{
					last = tc;
					what = i;
					break;
				}
			}
		}
		is[what] = 0;
		ans++;
		is[input[point]] = 1;
	}
	cout << ans << endl;
	return 0;
}



//#include <iostream>
//using namespace std;
//int F[101];
//int check[101];
//int how[101];
//int main() {
//	int n, k, ans = 0, cnt = 0, now;
//	cin >> k >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> F[i];
//		how[F[i]]++;
//	}
//	for (now = 1; now <= n; now++)
//	{
//		if (cnt == k)    break;
//		how[F[now]]--;
//		if (check[F[now]])   continue;
//		cnt++;
//		check[F[now]] = true;
//	}
//	if (now == n + 1)
//	{
//		printf("0\n");
//		return 0;
//	}
//	for (; now <= n; now++)
//	{
//		how[F[now]]--;
//		int maxi = 0, ind;
//		if (check[F[now]])   continue;
//		for (int i = 1; i <= n; i++)
//			if (check[i])
//			{
//				int flag = 0;
//				for (int j = now + 1; j <= n; j++)
//				{
//					if (F[j] == i)
//					{
//						flag = 1;
//						if (maxi < j)
//						{
//							maxi = j;
//							ind = F[j];
//						}
//						break;
//					}
//				}
//				if (!flag)
//				{
//					ind = i;
//					break;
//				}
//			}
//		check[ind] = false;
//		check[F[now]] = true;
//		ans++;
//	}
//	printf("%d\n", ans);
//	return 0;
//}