//#include <iostream>
//
//int in[100001] = { 0 }, dynamic[100001] = { 0 }, LIS[100001] = { 0 } ;
//
//int main()
//{
//	int n;
//
//	while (scanf("%d", &n) != EOF)
//	{
//		int LIS_max = 0;
//		for (int i = 1; i <= n; i++)
//			scanf("%d", &in[i]);
//
//		dynamic[1] = 1;
//		for (int i = 1; i <= n; i++)
//		{
//			int max = 0;
//			for (int j = LIS_max; j > 0; j--)
//			{
//				if (in[LIS[j]] < in[i])
//				{
//					max = j;
//					break;
//				}
//			}
//
//			dynamic[i] = max + 1;
//			if (LIS[dynamic[i]] == 0 || in[i] < in[LIS[dynamic[i]]])
//			{
//				LIS[dynamic[i]] = i;
//				if (LIS_max < dynamic[i])
//					LIS_max = dynamic[i];
//			}
//
//		}
//
//		int ans_max = 0;
//		for (int i = 1; i <= n; i++)
//		{
//			if (dynamic[i] > ans_max)
//			{
//				ans_max = dynamic[i];
//			}
//		}
//
//		printf("%d\n", ans_max);
//
//		int i = 1;
//		while (LIS[i] != 0 && dynamic[i] != 0)
//		{
//			LIS[i] = 0;
//			dynamic[i] = 0;
//			i++;
//		}
//
//	}
//}


#include<iostream>
using namespace std;
int input[1000001], seq[100001], LIS[100001];


int main()
{


	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i < n; i++)
			scanf("%d", input[i]);

		seq[1] = 1;
		LIS[1] = 1;
		int lisptr = 1;
		int seqnum = 1;
		for (int i = 2; i < n; i++)
		{
			if (input[i] > LIS[lisptr])
			{
				LIS[++lisptr] = input[i];
				seqnum++;
				seq[i] = seqnum;
			}
			else
			{
				for(int =)


			}
		}


	}



}