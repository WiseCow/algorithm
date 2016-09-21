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