//https://www.acmicpc.net/problem/1699
#include<iostream>
using namespace std;
int arr[100001];
int main()
{
	int a;
	scanf("%d", &a);

	for (int i = 1; i <= a; i++)
	{
		arr[i] = i;


		for (int j = 1; j*j <= i; j++)
		{
			if (arr[i] > arr[i - j*j] + 1)
				arr[i] = arr[i - j*j] + 1;
		}
	}

	printf("%d\n", arr[a]);
}


//#include<iostream>
//using namespace std;
//int arr[100000];
//
//int main()
//{
//	int a;
//	scanf("%d", &a);
//
//	for (int i = 1; i <= a; i++)
//	{
//		arr[i] = i;
//
//
//		for (int j = 1; j*j <= i; j++)
//		{
//			if (arr[i] > arr[i - j*j] + 1)
//			{
//				arr[i] = arr[i - j*j] + 1;
//			}
//		}
//	}
//
//
//	cout << arr[a] << endl;
//
//
//}