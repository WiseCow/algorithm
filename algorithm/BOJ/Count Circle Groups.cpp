#include<iostream>
using namespace std;
int Narr[3005][3];

int find(int x, int group[3005])
{
	if (x == group[x]) {
		return x;
	}
	else {
		int y = find(group[x], group);
		group[x] = y;
		return y;
	}

}



void Union(int x, int y, int group[3005])
{
	x = find(x, group);
	y = find(y, group);
	group[y] = x;
}



int main()
{
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{

		int N;
		scanf("%d", &N);
		int group[3005] = { 0 };
		for (int i = 1; i <= N; i++)
			group[i] = i;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d %d %d", &Narr[i][0], &Narr[i][1], &Narr[i][2]);

			for (int h = 1; h < i; h++)
			{
				int dx = Narr[i][0] - Narr[h][0];
				int dy = Narr[i][1] - Narr[h][1];
				int dc = Narr[i][2] + Narr[h][2];
				dx *= dx;
				dy *= dy;
				dc *= dc;

				if (dx + dy <= dc)
				{
					Union(h, i, group);
				}
			}
		}

		int maxx = 0;
		bool gro[3005] = { 0 };
		for (int i = 1; i <= N; i++)
		{
			int x = find(i, group);
			if (gro[x] == 0)
			{
				gro[x] = 1;
				maxx++;
			}
		}
		printf("%d\n", maxx);




	}
}
//#include<iostream>
//using namespace std;
//int tc;
//int Narr[3005][3];
//
//int main()
//{
//	scanf("%d", &tc);
//
//	for (int itr = 0; itr < tc; itr++)
//	{
//		int N;
//		scanf("%d", &N);
//		int group[3005] = { 0 };
//		int gp = 1;
//		for (int i = 1; i <= N; i++)
//		{
//			scanf("%d %d %d", &Narr[i][0], &Narr[i][1], &Narr[i][2]);
//			if (i == 1)
//				group[i] = gp;
//			else
//			{
//				bool flag = 0;
//				for (int k = 1; k < i; k++)
//				{
//					int difx = Narr[k][0] - Narr[i][0];
//					int dify = Narr[k][1] - Narr[i][1];
//					int dist = Narr[k][2] + Narr[i][2];
//					dist *= dist;
//					difx *= difx;
//					dify *= dify;
//					if ((difx + dify) <= dist)
//					{
//						if (flag == 0)
//						{
//							flag = 1;
//							group[i] = group[k];
//							
//						}
//						else
//						{
//							int i = group[k];
//							for (int p = 1; p < i; p++)
//								if (group[p] == i)
//									group[p] = group[i];
//							group[k] = group[i];
//						}
//					}
//				}
//				if (flag == 0)
//					group[i] = ++gp;
//			}
//		}
//		int maxx = 0;
//		bool gro[3005] = { 0 };
//		for (int i = 1; i <= N; i++)
//		{
//			if (gro[group[i]]==0)
//			{
//				gro[group[i]] = 1;
//				maxx++;
//			}
//		}
//		printf("%d\n", maxx);
//	}
//
//}