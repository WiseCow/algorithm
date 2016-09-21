//https://www.acmicpc.net/problem/9009
#include<iostream>
using namespace std;
int fibo[100] = { 0,1,1,2,3 };
int arr[50];

int main()
{
	for (int i = 5; i < 46; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		int input;
		scanf("%d", &input);

		int p = 0;
		for (int k = 45; k > 0; k--)
		{
			if (input == 0)
				break;
			if (fibo[k] <= input)
			{
				input -= fibo[k];
				arr[p++] = k;
			}
		}
		p--;
		for (; p >= 0; --p)
		{
			printf("%d ", fibo[arr[p]]);
		}
		printf("\n");
	}
}






//#include<iostream>
//using namespace std;
//bool flag;
//int arr[45];
//
//void solve(bool chk[45],int i, int a)
//{
//	if (a - arr[i] < 0)
//		return;
//	else
//	{
//		chk[i] = 1;
//		a -= arr[i];
//		if (a == 0)
//		{
//			flag = 1;
//			int k;
//			for ( k = 1; k < 45; k++)
//			{
//				if (chk[k] == true)
//				{
//					printf("%d",arr[k]);
//					break;
//				}
//			}
//			k++;
//			for (k; k < 45; k++)
//			{
//				if (chk[k] == true)
//				{
//					printf(" %d",arr[k]);
//				}
//			}
//			printf("\n");
//			return;
//		}
//		for (int k = i - 1; k > 0&&flag==0; k--)
//		{
//			if(arr[k]<=a)
//				solve(chk, k, a);
//		}
//		chk[i] = 0;
//	}
//}
//
//
//int main()
//{
//
//	int a,b=3;
//	arr[1] = 1; arr[2] = 1;
//	while (b!=45)
//	{
//		arr[b++] = arr[b - 1] + arr[b - 2];
//	}
//
//	cin >> a;
//	for (int l = 0; l < a; l++)
//	{
//		flag = 0;
//		int o;
//		cin >> o;
//		if (o == 0)
//		{
//			cout << 0 << endl;
//			continue;
//		}
//		bool chk[45] = { 0 };
//		for (int i = 44; i > 0 && flag == 0; i--)
//		{
//			if (arr[i] <= o)
//			solve(chk, i, o);
//		}
//	}
//
//
//}
//#include<iostream>
//using namespace std;
//bool flag;
//int arr[46];
//int main()
//{
//
//	int a, b = 3;
//	arr[1] = 1; arr[2] = 1;
//	while (b != 46)
//	{
//		arr[b++] = arr[b - 1] + arr[b - 2];
//	}
//
//	cin >> a;
//	for (int l = 0; l < a; l++)
//	{
//		flag = 0;
//		int o;
//		cin >> o;
//		if (o == 0)
//		{
//			cout << 0 << endl;
//			continue;
//		}
//		bool chk[45] = { 0 };
//
//		int i = 45;
//		int ans[46] = { 0 };
//		int idx=0;
//		while (o != 0)
//		{
//			for (; i > 1; i--)
//			{
//				if (arr[i] <= o)
//				{
//					o -= arr[i];
//					chk[i] = 1;
//					ans[idx++] = arr[i];
//				}
//			}
//		}
//
//
//
//		for (i = idx-1;i>=0; i--)
//		{
//				
//				printf("%d ", ans[i]);
//				flag = 1;
//		}
//		printf("\n");
//	}
//}