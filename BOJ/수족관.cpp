#include<cstdio>
#include<vector>
using namespace std;
int n,x,y,px,py,sx,sy,fx,fy;
vector<pair<int, int>>vc[40000];
int main()
{
	scanf("%d", &n);
	scanf("%d %d", &x, &y);
	for (int i = 0; i < n-1; i++)
	{
		scanf("%d %d", &x, &y);
		if (px == 0 && py == 0)
		{
			px = x;
			py = y;
			continue;
		}
		if (py == y)
		{
			for (int k = px; k < x; k++)
			{
				vc[k].push_back({ 0,y });
			}
			py = y;
			px = x;
		}
		else
		{
			py = y;
			px = x;
		}
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &sx, &sy, &fx, &fy);
		for (int k = sx; k < fx; k++)
			vc[k][0].first = vc[k][0].second;
		int ty=sy;
		for (int k = sx-1; k >= 0; k--)
		{
			if (vc[k][0].second>=ty)
			{
				if (vc[k][0].first < ty)
				{
					vc[k][0].first = ty;
				}
			}
			else
			{
				ty = vc[k][0].second;
				vc[k][0].first = ty;
			}
		}
		ty = sy;
		for (int k = fx; k <x; k++)
		{
			if (vc[k][0].second>ty)
			{
				if (vc[k][0].first < ty)
				{
					vc[k][0].first = ty;
				}
			}
			else
			{
				ty = vc[k][0].second;
				vc[k][0].first = ty;
			}
		}
	}
	int sum=0;
	for (int i = 0; i < x; i++)
		sum += vc[i][0].second - vc[i][0].first;

	printf("%d", sum);

}