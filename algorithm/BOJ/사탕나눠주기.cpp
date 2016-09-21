//https://www.acmicpc.net/problem/5721
#include<iostream>
using namespace std;
int r[1000001];
int c[1000001];

int main()
{
	while (1)
	{
		int M, N;
		scanf("%d %d", &M, &N);
		if (M == 0)break;

		int maxxx = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int a;
				scanf("%d", &a);

				r[j] = a;

				if (j >= 1)
				{
					r[j] = r[j]>r[j - 1] ? r[j] : r[j - 1];
					r[j] = r[j] > (r[j - 2] + a) ? r[j] : r[j - 2] + a;
				}
			}
			int maxx = 0;
			for (int l = 0; l < N; l++)
				if (maxx < r[l])
					maxx = r[l];

			c[i] = maxx;

			if (i >= 1)
			{
				c[i] = c[i]>c[i - 1] ? c[i] : c[i - 1];
				c[i] = c[i] > c[i - 2] + maxx ? c[i] : c[i - 2] + maxx;
			}
			if (c[i] > maxxx)
			{
				maxxx = c[i];
			}
		}
		cout << maxxx << endl;
	}
}